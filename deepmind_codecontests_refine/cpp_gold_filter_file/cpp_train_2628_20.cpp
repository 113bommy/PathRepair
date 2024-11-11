#include <bits/stdc++.h>
using namespace std;
const long long INFLL = 1e18;
const int MAXN = 3e5;
const long long INF = 1e9;
const long long kek = 998244353;
const long long mod = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  long long n, m;
  for (int o = 0; o < t; o++) {
    cin >> n >> m;
    if (n * m > n + m) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
