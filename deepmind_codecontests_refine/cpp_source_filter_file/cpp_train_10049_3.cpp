#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 256;
const char nxtl = '\n';
const double eps = (double)1e-9;
template <typename T>
inline bool updmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool updmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int n, k, a[MAXN];
int t[MAXN * 4];
void upd(int pos, int val, int x = 1, int tl = 1, int tr = n) {
  if (tl == tr) {
    t[x] = val;
    return;
  }
  int mid = tl + tr >> 1;
  if (pos <= mid)
    upd(pos, val, x + x, tl, mid);
  else
    upd(pos, val, x + x + 1, mid + 1, tr);
  t[x] = t[x + x] + t[x + x + 1];
}
int get(int l, int r, int x = 1, int tl = 1, int tr = n) {
  if (tl > r || tr < l) return 0;
  if (tl >= l && tr <= r) return t[x];
  int mid = tl + tr >> 1;
  return get(l, r, x + x, tl, mid) + get(l, r, x + x + 1, mid + 1, tr);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) a[i] = i;
  for (int i = 1; i <= min(k, n / 2); ++i) {
    swap(a[i], a[n - i + 1]);
  }
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    res += get(a[i + 1], n);
    upd(a[i], 1);
  }
  cout << res;
  return 0;
}
