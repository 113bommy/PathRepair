#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, x[N], t[N], y[N], a[N], b[N], m;
vector<int> vec;
void readInput() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    vec.push_back(y[i] = x[i]);
  }
  cin >> m;
  for (int i = 0, t1, t2; i < m; i++) {
    cin >> t[i] >> t1 >> t2;
    if (t[i] & 1) {
      a[i] = y[--t1];
      vec.push_back(b[i] = (y[t1] += t2));
    } else {
      vec.push_back(a[i] = t1);
      vec.push_back(b[i] = t2);
    }
  }
}
void comperes() {
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++)
    x[i] = lower_bound(vec.begin(), vec.end(), x[i]) - vec.begin();
  for (int i = 0; i < m; i++) {
    a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
    b[i] = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin();
  }
}
struct node {
  long long sum = 0, cnt = 0, ans = 0;
  void merge(node a, node b) {
    cnt = a.cnt + b.cnt;
    sum = a.sum + b.sum;
    ans = a.ans + b.ans + b.sum * a.cnt - a.sum * b.cnt;
  }
} seg[N << 2];
void update(int x, int val = 1, int s = 0, int e = N, int id = 1) {
  if (e - s == 1) {
    seg[id].cnt += val;
    seg[id].sum += val * vec[x];
    return;
  }
  int mid = s + e >> 1;
  x < mid ? update(x, val, s, mid, id << 1)
          : update(x, val, mid, e, id << 1 | 1);
  seg[id].merge(seg[id << 1], seg[id << 1 | 1]);
}
node get(int l, int r, int s = 0, int e = N, int id = 1) {
  if (l <= s && e <= r) return seg[id];
  node res;
  if (l >= e || s >= r) return res;
  int mid = e + s >> 1;
  res.merge(get(l, r, s, mid, id << 1), get(l, r, mid, e, id << 1 | 1));
  return res;
}
void solve() {
  for (int i = 0; i < n; i++) update(x[i]);
  for (int i = 0; i < m; i++) {
    if (t[i] & 1)
      update(a[i], -1), update(b[i]);
    else
      cout << get(a[i], b[i] + 1).ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  readInput(), comperes(), solve();
}
