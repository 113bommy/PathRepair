#include <bits/stdc++.h>
using namespace std;
int nd(int n) {
  int i;
  for (i = 2; i <= sqrt(n); i++)
    if (n % i == 0) break;
  if (i > sqrt(n))
    return n;
  else
    return i;
}
int main() {
  int n;
  unsigned long long int kol;
  cin >> n;
  kol = n;
  while (n != 1) {
    int x = nd(n);
    while (!(n % x)) n = n / x, kol += n;
  }
  cout << kol;
  return 0;
}
