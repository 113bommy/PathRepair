#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    long long int mx = 0;
    string name = "";
    while (n--) {
      string s;
      cin >> s;
      long long int su, un, a, b, c, d, e;
      cin >> su >> un >> a >> b >> c >> d >> e;
      long long int sum = su * 100 - un * 50 + a + b + c + d + e;
      if (sum > mx) {
        mx = sum;
        name = s;
      }
    }
    cout << name;
  }
}
