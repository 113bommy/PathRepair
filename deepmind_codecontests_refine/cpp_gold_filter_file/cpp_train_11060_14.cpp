#include <bits/stdc++.h>
using namespace std;
long long n, sum;
void solve() {
  scanf("%lld", &n);
  sum = 0;
  n /= 2;
  if (n % 2 != 0) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    printf("%d ", i * 2);
    sum += i * 2;
  }
  for (int i = 1; i < n; i++) {
    printf("%d ", i * 2 - 1);
    sum -= (i * 2 - 1);
  }
  printf("%lld\n", sum);
  return;
}
int t;
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) solve();
  return 0;
}
