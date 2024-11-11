#include <bits/stdc++.h>
using namespace std;
string vow = "aeiou";
int month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const long double pie = 3.1415926535897932384626;
const long long mod = 1e9 + 7;
vector<array<int, 3> > v;
int q, n;
map<int, int> h;
void read() {
  cin >> q;
  n = q;
  v.resize(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    h[l];
    h[r];
    v[i] = {l, r, i};
  }
}
void compress() {
  int cnt = 0;
  for (auto &temp : h) {
    temp.second = cnt;
    cnt++;
  }
  for (int i = 0; i < q; i++) {
    v[i][0] = h[v[i][0]];
    v[i][1] = h[v[i][1]];
  }
}
bool comp(const array<int, 3> &a, const array<int, 3> &b) {
  if (a[1] < b[1]) return true;
  return false;
}
int l, r;
vector<int> tree;
int query(int node = 0, int start = 0, int end = n - 1) {
  if (start > r || end < l) return 0;
  if (start >= l && end <= r) return tree[node];
  int mid = start + end >> 1;
  int q1 = query(2 * node + 1, start, mid);
  int q2 = query(2 * node + 2, mid + 1, end);
  return (q1 + q2);
}
void update(int node = 0, int start = 0, int end = n - 1) {
  if (start == end) {
    tree[node]++;
    return;
  }
  int mid = start + end >> 1;
  if (l <= mid)
    update(2 * node + 1, start, mid);
  else
    update(2 * node + 2, mid + 1, end);
  tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
void solve(int test_case) {
  read();
  compress();
  sort(v.begin(), v.end(), comp);
  tree.resize(16e5);
  vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    l = v[i][0];
    r = v[i][1];
    int val = query();
    ans[v[i][2]] = val;
    update();
  }
  for (int i = 0; i < q; i++) cout << ans[i], cout << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
