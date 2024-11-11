#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int mod = 1000000007;
const double PI = 3.141592653589793238;
const long long int INF = 1e18;
const long long int p = 998244353;
int main() {
  long long int t = 1;
  cin >> t;
  for (int test = 0; test < t; test++) {
    long long int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      if ((s1[i] == '1' && s2[i] == '0') || (s1[i] == '0' && s2[i] == '1')) {
        ans += 2;
      } else if (s1[i] == '1' && s2[i] == '1') {
        if (i < n - 1) {
          if (s1[i + 1] == '0' || s2[i + 1] == '0') {
            ans += 2;
            i++;
          }
        }
      } else if (s1[i] == '0' && s2[i] == '0') {
        if (s1[i + 1] == '1' && s2[i + 1] == '1') {
          ans += 2;
          i++;
        } else {
          ans += 1;
        }
      }
    }
    cout << ans << "\n";
  }
}
