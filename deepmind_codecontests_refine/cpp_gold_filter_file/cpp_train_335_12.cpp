#include <bits/stdc++.h>
using namespace std;
vector<long long> nclaws(2000001, 0);
void solve() {
  int n;
  cin >> n;
  cout << ((nclaws[n] * 4) % 1000000007) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  nclaws[1] = 0;
  nclaws[2] = 0;
  nclaws[3] = 1;
  nclaws[4] = 1;
  for (int i = 5; i < 2000001; i++) {
    nclaws[i] = nclaws[i - 1] + 2 * nclaws[i - 2];
    if (i % 3 == 0) nclaws[i]++;
    nclaws[i] = nclaws[i] % 1000000007;
  }
  int t = 1;
  cin >> t;
  while (t--) solve();
}
