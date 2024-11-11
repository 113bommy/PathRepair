#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793;
const int INF = 1e9;
const double inf = 1e20;
int main() {
  long long n, sum = 0, ans = 0;
  scanf("%I64d", &n);
  double R = n;
  long long tmp = n;
  for (long long i = 1; i <= n; i++) {
    double r = i;
    long long k = (long long)sqrt(R * R - r * r);
    ans += (tmp == k ? 1 : tmp - k);
    tmp = k;
  }
  if (n == 0)
    printf("1\n");
  else
    printf("%I64d\n", ans * 4);
  return 0;
}
