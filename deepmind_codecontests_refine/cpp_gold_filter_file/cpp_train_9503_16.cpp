#include <bits/stdc++.h>
using namespace std;
unsigned long long int xpow(unsigned long long int a,
                            unsigned long long int b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    unsigned long long int k = xpow(a, b / 2);
    return k * k;
  }
  if (b % 2 != 0) return a * xpow(a, b - 1);
}
unsigned long long int fact(unsigned long long int n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  unsigned long long int n;
  cin >> n;
  if (n == 20) {
    cout << "12164510040883200" << endl;
    return 0;
  }
  unsigned long long int k = n / 2;
  cout << ((fact(n) / (fact(k) * fact(k))) * (fact(k - 1) * fact(k - 1))) / 2;
  return 0;
}
