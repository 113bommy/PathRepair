#include <bits/stdc++.h>
const long long LINF = 1e18;
const int INF = 1e9;
const int M = 1e9 + 7;
const double EPS = 1.0e-9;
const double PI = acos(-1.0);
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = a + b;
  int ansA = 1, ansB = 1, ansC = c;
  int lim = 1e4 + 10;
  for (int curA = 1; curA < lim; curA++) {
    for (int ab = 1; ab < (lim / curA); ab++) {
      int curB = ab * curA;
      int curC = (c / curB) * curB;
      if (c - curC > curC + curB - c) curC += curB;
      if (abs(a - curA) + abs(b - curB) + abs(c - curC) < ans) {
        ans = abs(a - curA) + abs(b - curB) + abs(c - curC);
        ansA = curA;
        ansB = curB;
        ansC = curC;
      }
    }
  }
  cout << ans << "\n";
  cout << ansA << " " << ansB << " " << ansC << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
