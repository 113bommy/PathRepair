#include <bits/stdc++.h>
using namespace std;
long long i, j, sum = 0, c = 0, ctr = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  string s;
  long long t;
  cin >> t;
  while (t--) {
    ctr = 0;
    cin >> n >> s;
    if (n < 11) {
      cout << "NO\n";
    } else if (n == 11 && s[0] != 8) {
      cout << "NO\n";
    } else {
      for (i = 0; i < n; i++) {
        if (s[i] != '8')
          ctr++;
        else
          break;
      }
      if (n - ctr >= 11)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
