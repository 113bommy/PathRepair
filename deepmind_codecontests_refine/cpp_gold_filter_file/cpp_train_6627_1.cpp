#include <bits/stdc++.h>
using namespace std;
map<long long, long long> m;
map<pair<long long, long long>, long long> M;
void solve() {
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  long long c = 0;
  for (__typeof((n)) i = (0); i < (n); i++) {
    long long x, vx, vy;
    cin >> x >> vx >> vy;
    c += m[a * vx - vy];
    c -= M[{vx, vy}];
    m[a * vx - vy]++;
    M[{vx, vy}]++;
  }
  cout << 2 * c << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
