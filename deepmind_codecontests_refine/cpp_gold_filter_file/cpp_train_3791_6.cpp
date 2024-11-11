#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const long long int INFLL = 1e18 + 10;
const long double EPS = 1e-8;
const long double EPSLD = 1e-14;
const long long int MOD = 1000000007;
template <class T>
T &chmin(T &a, const T &b) {
  return a = min(a, b);
}
template <class T>
T &chmax(T &a, const T &b) {
  return a = max(a, b);
}
const int MAX_N = 5010;
int n, m;
int t[MAX_N], l[MAX_N], r[MAX_N], x[MAX_N];
int a[MAX_N];
int ans[MAX_N];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (0); i < (int)(n); i++) a[i] = 5 * 1e8;
  for (int i = (0); i < (int)(m); i++)
    scanf("%d %d %d %d", &t[i], &l[i], &r[i], &x[i]);
  for (int i = m - 1; i >= 0; i--) {
    if (t[i] == 1)
      for (int j = (l[i] - 1); j < (int)(r[i]); j++) a[j] -= x[i];
    else
      for (int j = (l[i] - 1); j < (int)(r[i]); j++) chmin(a[j], x[i]);
  }
  for (int i = (0); i < (int)(n); i++) ans[i] = a[i];
  for (int i = (0); i < (int)(m); i++) {
    if (t[i] == 1)
      for (int j = (l[i] - 1); j < (int)(r[i]); j++) a[j] += x[i];
    else {
      int res = -INF;
      for (int j = (l[i] - 1); j < (int)(r[i]); j++) chmax(res, a[j]);
      if (res != x[i]) return puts("NO");
    }
  }
  printf("YES\n");
  for (int i = (0); i < (int)(n); i++)
    printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
