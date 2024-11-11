#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (!(n % i)) return false;
  return true;
}
int f(int n, int k) {
  if (k > n || !isPrime(k)) return 0;
  int res = n / k;
  for (int i = 2; i < k && i <= n / k; i++) res -= f(n / k, i);
  return res;
}
int main() {
  int a, b, k;
  scanf("%d%d", &a, &b);
  scanf("%d", &k);
  if ((long long)k * k > b)
    printf("%d\n", a <= k && k <= b && !isPrime(k) ? 1 : 0);
  else
    printf("%d\n", f(b, k) - f(a - 1, k));
}
