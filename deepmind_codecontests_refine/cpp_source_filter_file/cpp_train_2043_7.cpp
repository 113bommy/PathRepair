#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Int(T &n) {
  n = 0;
  int f = 1;
  register int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
  n = n * f;
}
template <typename T>
T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}
template <typename T>
inline void umin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void umax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T, typename W>
inline void Int(T &x, W &y) {
  Int(x), Int(y);
}
template <typename T, typename W, typename Q>
inline void Int(T &x, W &y, Q &z) {
  Int(x, y), Int(z);
}
const int N = (int)1e5 + 5;
const int INF = (int)1e9 + 7;
const long long MOD = (long long)1e9 + 7;
int n, k, a[N], f[N << 2];
void MergeSort(int nd, int l, int r) {
  if (k < 1 or l + 1 == r) return;
  if (k - 2 < 0) return;
  int m = l + r >> 1;
  k -= 2;
  MergeSort(nd << 1, l, m);
  MergeSort(nd << 1 | 1, m, r);
  if (!f[nd << 1] and !f[nd << 1 | 1]) swap(a[l], a[m]);
  f[nd] = 1;
}
int main() {
  Int(n, k), k--;
  for (int i = 0; i <= n - 1; ++i) a[i] = i + 1;
  MergeSort(1, 0, n);
  if (k > 0) return !printf("-1\n");
  for (int i = 0; i <= n - 1; ++i) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
