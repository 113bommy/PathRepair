#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
const long long mod = 1e9 + 7;
map<int, int> mp;
vector<int> vec[maxn];
vector<pair<int, pair<int, int>>> vecc[maxn];
int n;
int fen[maxn], seg[maxn * 4];
int s[maxn], ans[maxn], num = 1;
int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
void upd(int x, int val) {
  for (; x < maxn; x += x & -x) fen[x] += val;
}
int get(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += fen[x];
  return res;
}
void build(int l = 1, int r = n + 1, int id = 1) {
  if (r - l == 1) {
    seg[id] = s[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, id * 2);
  build(mid, r, id * 2 + 1);
  seg[id] = gcd(seg[id * 2], seg[id * 2 + 1]);
}
int query(int st, int en, int l = 1, int r = n + 1, int id = 1) {
  if (st >= r || en <= l) return 0;
  if (st <= l && en >= r) return seg[id];
  int mid = (l + r) / 2;
  return gcd(query(st, en, l, mid, id * 2), query(st, en, mid, r, id * 2 + 1));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (mp[s[i]] == 0) mp[s[i]] = num++;
    vec[mp[s[i]]].push_back(i);
  }
  build();
  cin >> t;
  for (int i = 0; i < t; i++) {
    int l, r, cur;
    cin >> l >> r;
    cur = query(l, r + 1);
    if (mp[cur] != 0)
      vecc[mp[cur]].push_back(make_pair(i, make_pair(l, r)));
    else
      ans[i] = r - l + 1;
  }
  for (auto q : mp) {
    int cur = q.second;
    for (auto x : vec[cur]) upd(x, 1);
    for (auto x : vecc[cur]) {
      int num = x.first, l = x.second.first, r = x.second.second;
      ans[num] = r - l + 1 - (get(r) - get(l - 1));
    }
    for (auto x : vec[cur]) upd(x, -1);
  }
  for (int i = 0; i < t; i++) cout << ans[i] << "\n";
}
