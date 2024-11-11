#include <bits/stdc++.h>
using namespace std;
int const uu[4] = {1, -1, 0, 0};
int const vv[4] = {0, 0, 1, -1};
int const maxn = 50005;
int const inf = 0x3f3f3f3f;
long long const INF = 0x7fffffffffffffffll;
double eps = 1e-10;
double pi = acos(-1.0);
long long f[100000 + 5];
int main() {
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    scanf("%I64d", &f[i]);
  }
  long long aa = 1000000000000000000, bb = -1;
  for (int i = 1; i <= k; ++i) {
    long long left = n - n / f[i] * f[i];
    if (left < aa) {
      aa = left;
      bb = i;
    }
  }
  printf("%I64d %I64d\n", bb, n / f[bb]);
  return 0;
}
