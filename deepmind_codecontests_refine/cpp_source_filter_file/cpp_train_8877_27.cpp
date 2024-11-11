#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;
using namespace std;
long long int t, n, m, a, b, c, d, ans = 0;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    cout << min(a + b, c + d) << "\n";
  }
  return 0;
}
