#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a, b;
  cin >> a >> b;
  long long x = gcd(a, b);
  long long m = min(a, b);
  long long ans = 1;
  for (int i = 2; i <= m; i++) ans = ans * i;
  cout << ans * x;
}
