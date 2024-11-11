#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const long long N = 1e6;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long mx = 0, sum = 0;
    while (n--) {
      long long x;
      cin >> x;
      mx = max(mx, x);
      sum += x;
    }
    if (mx * 2 > sum || sum % 2 == 0)
      cout << "T\n";
    else
      cout << "HL\n";
  }
  return 0;
}
