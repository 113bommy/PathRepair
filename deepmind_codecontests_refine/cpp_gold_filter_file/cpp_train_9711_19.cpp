#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void dmin(T& x, T y) {
  y < x ? x = y : 0;
}
template <class T>
inline void dmax(T& x, T y) {
  y > x ? x = y : 0;
}
template <class T>
inline void dmin(T& x, vector<T> y) {
  for (auto t : y) t < x ? x = t : 0;
}
template <class T>
inline void dmax(T& x, vector<T> y) {
  for (auto t : y) t > x ? x = t : 0;
}
const int N = 5 + 1e6;
const long long INF = -2e18;
int n, k;
long long gk(int x, long long a[], int i, long long f) {
  return a[x] + (i - x) / 3 * f;
}
bool cmp(int x, int y, long long a[], int i, long long f) {
  return gk(x, a, i, f) > gk(y, a, i, f);
}
void opera(long long a[], int n, long long f, int k) {
  static long long b[N];
  static long long q[3][N], left[3], right[3];
  for (int i = 0; i < 3; ++i) left[i] = 1, right[i] = 0;
  for (int i = 0; i < n; ++i) b[i] = INF;
  for (int i = 0; i < n; ++i) {
    int t = i % 3;
    while (left[t] <= right[t] && q[t][left[t]] < i - 3 * k) ++left[t];
    while (left[t] <= right[t] && cmp(i, q[t][right[t]], a, i, f)) --right[t];
    q[t][++right[t]] = i;
    b[i] = gk(q[t][left[t]], a, i, f);
  }
  for (int i = 0; i < n; ++i) a[i] = b[i];
}
void opera2(long long a[], int n, long long f, int k) {
  static long long f1[N], f2[N];
  for (int i = 0; i < n; ++i) {
    f1[i] = f2[i] = a[i];
    for (int j = 1; j < 10 && i - j >= 0; ++j) f2[i] = max(f2[i], a[i - j]);
  }
  opera(f1, n, f, 3 * k);
  opera(f2, n, f, 3 * (k - 1));
  for (int i = 0; i < n; ++i) a[i] = max(f1[i], f2[i]);
}
long long a[N], b[N];
int main() {
  int k;
  scanf("%d", &k);
  long long f[6];
  for (int i = 0; i < 6; ++i) scanf("%lld", &f[i]);
  a[0] = 0;
  n = 1;
  for (int i = 5; i >= 0; --i) {
    for (int j = 0; j < 10 * n; ++j) b[j] = INF;
    for (int j = 0; j < n; ++j) b[j * 10] = a[j];
    n *= 10;
    opera2(b, n, f[i], k);
    for (int j = 0; j < n; ++j) a[j] = b[j];
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", a[x]);
  }
  return 0;
}
