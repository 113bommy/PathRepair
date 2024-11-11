#include <bits/stdc++.h>
using namespace std;
vector<long long> prime;
void factors(long long n) {
  while (n % 2 == 0) {
    prime.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      prime.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) prime.push_back(n);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long p, q;
    cin >> p >> q;
    if (p % q != 0)
      cout << p << endl;
    else {
      prime.clear();
      factors(q);
      long long ans = 0;
      for (long long i = 0; i < prime.size(); i++) {
        long long temp = p;
        while (temp % prime[i] == 0) temp = temp / prime[i];
        ans = max(ans, temp);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
