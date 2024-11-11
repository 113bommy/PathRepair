#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
void solve() {
  int n;
  cin >> n;
  int oD = 1, oABC = 0;
  for (int i = 1; i <= n; i++) {
    int nD = (3 * oABC) % mod;
    int nABC = (2 * oABC + oD) % mod;
    oD = nD;
    oABC = nABC;
  }
  cout << oD;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
