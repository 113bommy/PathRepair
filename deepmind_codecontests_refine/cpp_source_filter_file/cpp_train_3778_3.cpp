#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  int t;
  cin >> t;
  long long p;
  int q;
  while (t--) {
    cin >> p >> q;
    if (p % q) {
      cout << p << endl;
      continue;
    }
    vector<int> prime;
    int x = q;
    for (int i = 2; i <= sqrt(q); ++i)
      if (x % i == 0) {
        prime.push_back(i);
        while (x % i == 0) x /= i;
      }
    if (x != 1) prime.push_back(x);
    long long ans = 1;
    for (int fact : prime) {
      long long x = p;
      while (q % fact == 0 && x % fact == 0) x /= fact;
      ans = max(ans, x);
    }
    cout << ans << endl;
  }
}
