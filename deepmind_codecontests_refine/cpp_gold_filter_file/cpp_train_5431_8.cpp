#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 22;
const double eps = 1e-7;
int n, b[maxn];
long long sum;
double a[maxn];
bool f[maxn];
int main() {
  scanf("%d", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lf", &a[i]);
    b[i] = a[i];
    if (fabs(a[i] - b[i]) < eps) f[i] = 1;
    sum += b[i];
    ;
  }
  if (sum > 0) {
    for (long long i = 1; i <= n; i++) {
      if (a[i] < 0 && f[i] == 0) {
        b[i]--;
        sum--;
      }
      if (!sum) break;
    }
  } else if (sum < 0) {
    for (long long i = 1; i <= n; i++) {
      if (a[i] > 0 && f[i] == 0) {
        b[i]++;
        sum++;
      }
      if (!sum) break;
    }
  }
  for (long long i = 1; i <= n; i++) {
    printf("%d\n", b[i]);
  }
  return 0;
}
