#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void JAISHREERAM() {
  long long int n, i, j, ans = 0, x, y;
  cin >> n >> x >> y;
  set<pair<long long int, long long int>> s;
  for (long long int i = 0; i < n; i++) {
    long long int cx, cy, cur, g;
    cin >> cx >> cy;
    cy = (cy - y);
    cx = (cx - x);
    g = gcd(cy, cx);
    cy /= g, cx /= g;
    s.insert({cx, cy});
  }
  cout << s.size();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int T = 1;
  for (int t = 1; t <= T; t++) {
    JAISHREERAM();
  }
  return 0;
}
