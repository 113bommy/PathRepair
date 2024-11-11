#include <bits/stdc++.h>
using namespace std;
inline int Get() {
  int res = 0, q = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') q = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return res * q;
}
const double eps = 1e-12, pi = M_PI;
const int oo = (int)2e9, mod = (int)1e9 + 7;
const long long INF = (long long)1e17;
const int N = 500;
typedef int arr[N + 10];
int i, j, k, p, n, m;
double ans, now;
arr a;
int main() {
  scanf(
      "%d"
      "%d"
      "\n",
      &n, &m);
  for (int i = (1), end = (n); i <= end; ++i) scanf("%d", a + i);
  for (int i = (1), end = (m); i <= end; ++i) {
    scanf(
        "%d"
        "%d"
        "%d"
        "\n",
        &j, &k, &p);
    now = ((double)a[j] + (double)a[k]) / (double)p;
    ans = ((ans) > (now) ? (ans) : (now));
  }
  printf(
      "%.8lf"
      "\n",
      ans);
  return 0;
}
