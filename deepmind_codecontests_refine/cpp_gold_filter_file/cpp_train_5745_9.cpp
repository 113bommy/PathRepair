#include <bits/stdc++.h>
using namespace std;
const long long int inf = (long long int)1e18 + 19;
const long long int mod = (long long int)1e9 + 7;
void cazz() {
  long long int t = 1, i, j, n;
  cin >> t;
  while (t--) {
    long long int m, k, a, b;
    cin >> n >> m >> k;
    bool f = 0;
    cin >> a;
    for (long long int i = 1; i < n; i++) {
      cin >> b;
      if (b <= a) {
        m += (a - b);
        a -= (a - b);
        m += min(a, k);
      } else {
        long long int yo = k - b + a;
        if (yo > 0)
          m += min(yo, a);
        else if (yo < 0) {
          m += yo;
          if (m < 0) f = 1;
        }
      }
      a = b;
    }
    if (f)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cazz();
  return 0;
}
