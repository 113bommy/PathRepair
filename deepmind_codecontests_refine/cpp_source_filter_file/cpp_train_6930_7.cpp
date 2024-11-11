#include <bits/stdc++.h>
using namespace std;
int soda(long long int n) {
  long long int k = 0;
  for (long long int i = 2; i <= n - 1; i++)
    if (n % i == 0) {
      k++;
      return 1;
      break;
    }
  if (n == 1) return 1;
}
long long int n, c, s, d = 0, f = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  while (d == 0) {
    f++;
    if (soda(n * f + 1) == 1) {
      cout << f;
      return 0;
    }
  }
  return 0;
}
