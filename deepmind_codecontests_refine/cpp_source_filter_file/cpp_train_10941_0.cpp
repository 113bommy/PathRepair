#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int minA = 1e18, minB = 1e18, minC = 1e18, minAB = 1e18,
                minBC = 1e18, minAC = 1e18, minABC = 1e18;
  for (long long int i = 0; i < n; i++) {
    long long int c;
    string s;
    cin >> c >> s;
    if (s.find('A') != -1 and s.find('B') != -1 and s.find('C') != -1)
      minABC = min(minABC, c);
    else if (s.find('A') != -1 and s.find('B') != -1)
      minAB = min(minAB, c);
    else if (s.find('A') != -1 and s.find('C') != -1)
      minAC = min(minAC, c);
    else if (s.find('B') != -1 and s.find('C') != -1)
      minBC = min(minBC, c);
    else if (s.find('A') != -1)
      minA = min(minA, c);
    else if (s.find('B') != -1)
      minB = min(minA, c);
    else if (s.find('C') != -1)
      minC = min(minA, c);
  }
  long long int x =
      min({minABC, minA + minB + minC, minAB + minC, minA + minBC, minAC + minB,
           minAB + minBC, minAC + minBC, minAC + minAB});
  cout << (x == 1e18 ? -1 : x) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(20);
  cout.setf(ios::fixed);
  long long int ttc = 1;
  while (ttc--) solve();
  return 0;
}
