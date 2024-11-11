#include <bits/stdc++.h>
using namespace std;
long long int comb(int n, int r) {
  long long dividend = 1;
  long long divisor = 1;
  for (int i = n; i > n - r; i--) dividend *= i;
  for (int i = r; i >= 1; i--) divisor *= i;
  return dividend / divisor;
}
long long int cyclicPerm(int n) {
  long long ans = 1;
  for (int i = 1; i <= n - 1; i++) ans *= i;
  return ans;
}
int main() {
  int n;
  cin >> n;
  printf("%lld", comb(n, n / 2) / 2 * cyclicPerm(n / 2) * cyclicPerm(n / 2));
}
