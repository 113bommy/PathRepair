#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
pair<long long, int> arr[N];
long long t[4 * N] = {};
inline void update(int v, int vl, int vr, int pos, long long val) {
  if (vl == vr) {
    t[v] = val;
    return;
  }
  int vm = vl + (vr - vl) / 2;
  if (pos <= vm)
    update(2 * v + 1, vl, vm, pos, val);
  else
    update(2 * v + 2, vm + 1, vr, pos, val);
  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}
inline long long get(int v, int vl, int vr, int l, int r) {
  if (r < vl || vr < l) return 0;
  if (l <= vl && vr <= r) return t[v];
  int vm = vl + (vr - vl) / 2;
  long long ql = get(2 * v + 1, vl, vm, l, r);
  long long qr = get(2 * v + 2, vm + 1, vr, l, r);
  return max(ql, qr);
}
inline bool c(pair<long long, int> x, pair<long long, int> y) {
  if (x.first != y.first)
    return x.first < y.first;
  else
    return x.second > y.second;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long r, h;
    cin >> r >> h;
    arr[i] = {1ll * r * r * h, i};
  }
  sort(arr, arr + n, c);
  for (int i = 0; i < n; i++) {
    long long res = get(0, 0, n - 1, 0, max(0, arr[i].second - 1));
    update(0, 0, n - 1, arr[i].second, res + arr[i].first);
  }
  cout << fixed << setprecision(6) << 3.14159265 * get(0, 0, n - 1, 0, n - 1)
       << '\n';
  return 0;
}
