#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (l >= (r + 1) / 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
