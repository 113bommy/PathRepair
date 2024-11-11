#include <bits/stdc++.h>
using namespace std;
const long long int Mod = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t-- > 0) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int e, f;
    e = a + b;
    f = d + c;
    e = max(e, f);
    cout << e << "\n";
  }
  return 0;
}
