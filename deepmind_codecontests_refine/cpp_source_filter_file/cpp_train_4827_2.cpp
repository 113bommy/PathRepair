#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long mod = 1e9 + 7.3;
int n;
double P[N], f[N], A[N], B[N];
char ch[N << 2];
double F(double X) { return 3.0 * X * X + 3.0 * X + 1; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", P + i);
  for (int i = 1; i <= n; i++) {
    A[i] = (A[i - 1] + 1) * P[i];
    B[i] = B[i - 1] + (2 * A[i - 1] + 1) * P[i];
  }
  printf("%.4lf\n", B[n]);
  return 0;
}
