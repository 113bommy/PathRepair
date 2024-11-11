#include <bits/stdc++.h>
using namespace std;
vector<long long> fact;
void f(long long n) {
  while (n % 2 == 0) {
    fact.push_back(2);
    n /= 2;
  }
  for (long long i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      fact.push_back(i);
      n /= i;
    }
  }
  if (n > 1) fact.push_back(n);
}
int32_t main() {
  long long n;
  cin >> n;
  f(n);
  if (fact.size() <= 1) {
    cout << 1 << endl << 0 << endl;
    return 0;
  }
  if (fact.size() == 2) {
    cout << 2 << endl;
    return 0;
  }
  cout << 1 << endl << fact[0] * fact[1] << endl;
  return 0;
}
