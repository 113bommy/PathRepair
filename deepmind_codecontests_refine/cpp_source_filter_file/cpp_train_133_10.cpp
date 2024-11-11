#include <bits/stdc++.h>
using namespace std;
vector<long long> primeFactors(long long n) {
  vector<long long> res;
  while (n % 2 == 0) {
    res.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      res.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) res.push_back(n);
  return res;
}
int main() {
  long long n;
  cin >> n;
  vector<long long> res = primeFactors(n);
  if (res.size() == 0) {
    cout << "1\n0\n";
    return 0;
  }
  if (res.size() == 2) {
    cout << "2\n";
    return 0;
  }
  long long ans = 1;
  for (long long i = 0; i < 2; ++i) {
    ans *= res[i];
  }
  cout << "1\n";
  cout << ans << "\n";
  return 0;
}
