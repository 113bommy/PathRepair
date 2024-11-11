#include <bits/stdc++.h>
using namespace std;
int M[40];
int main() {
  unsigned long long n;
  scanf("%lld", &n);
  unsigned long long L = 2 * n - 2;
  unsigned long long ans = 2 * 4 * 3 * pow(4, L - n - 1);
  unsigned long long p = L - n + 1 - 2;
  if (p > 0) ans += p * 4 * 3 * 3 * pow(4, L - n - 2);
  cout << ans << endl;
}
