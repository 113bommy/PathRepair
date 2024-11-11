#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long u = 0;
    long long ans = s.size();
    while (u < n) {
      u++;
      if (s.size() < n) {
        string t = s.substr(u, s.size() - u);
        for (long long i = 0; i < s[u - 1] - 48; ++i) s += t;
      }
      ans = (ans + (ans - u) * (s[u - 1] - 49) + mod) % mod;
    }
    cout << (ans + mod) % mod << endl;
  }
  return 0;
}
