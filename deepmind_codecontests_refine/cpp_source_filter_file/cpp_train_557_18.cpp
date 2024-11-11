#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int mx = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  long long t, ans = 0;
  string s;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (abs(ans - b) <= 500) {
      s += 'A';
      ans -= b;
    } else {
      s += 'G';
      ans += a;
    }
  }
  cout << s << "\n";
}
