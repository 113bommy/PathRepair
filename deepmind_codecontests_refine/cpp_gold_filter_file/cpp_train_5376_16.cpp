#include <bits/stdc++.h>
using namespace std;
const long long mod = 2e9;
long long a, m;
inline long long exp(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  if (n % 2 == 0) return exp((x * x) % mod, n / 2);
  if (n % 2 == 1) return (x * exp((x * x) % mod, n / 2)) % mod;
}
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> m;
  cout << m % exp(2, a);
  return 0;
}
