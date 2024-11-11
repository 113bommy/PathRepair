#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const double eps = 1e-10;
const int max_index = 62;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
inline int read() {
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  int x = 0;
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
double P[maxn];
int main() {
  int n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    int l = read(), r = read();
    int d = r / k - (l - 1) / k;
    P[i] = 1.0 - 1.0 * d / (r - l + 1);
  }
  P[0] = P[1];
  P[n + 1] = P[1];
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    double p = 1 - P[i] * P[i - 1];
    ans += p * 2000;
  }
  printf("%.10f\n", ans);
  return 0;
}
