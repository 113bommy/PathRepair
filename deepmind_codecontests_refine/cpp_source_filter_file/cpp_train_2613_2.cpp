#include <bits/stdc++.h>
using namespace std;
long long powm(long long base, long long exp, long long mod = 1000000007) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % mod;
    exp >>= 1, base = (base * base) % mod;
  }
  return ans;
}
long long ctl(char x, char an = 'a') { return (long long)(x - an); }
char ltc(long long x, char an = 'a') { return (char)(x + an); }
long long buy = -1000111000111000111LL, sell = 1000111000111000111LL;
set<long long> rem;
int main() {
  long long n, p, tot = 0, ans = 1;
  string second;
  cin >> n;
  for (long long i = 1; i < n + 1; i++) {
    cin >> second >> p;
    if (second == "ADD") {
      if (p > buy and p < sell) tot = 0;
      rem.insert(p);
    } else {
      if (p > buy and p < sell)
        ans = (ans * 2LL) % 1000000007;
      else if (p != buy and p != sell)
        ans = 0;
      auto it1 = rem.lower_bound(p);
      if (it1 == rem.begin())
        buy = -1000111000111000111LL;
      else
        buy = *(--it1);
      auto it2 = rem.upper_bound(p);
      if (it2 == rem.end())
        sell = 1000111000111000111LL;
      else
        sell = *(it2);
      rem.erase(p), tot = 0;
    }
  }
  ans = (ans * (tot + 1) % 1000000007) % 1000000007;
  cout << ans;
  return 0;
}
