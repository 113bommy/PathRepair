#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
long long dp[4444];
long long v[4444], d[4444];
int goOUT[4444];
int main() {
  std::ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> d[i] >> dp[i];
  }
  for (int i = 0; i < n; i++) {
    if (goOUT[i]) continue;
    long long tot = v[i];
    int r = 1;
    for (int j = i + 1; j < n; j++) {
      if (goOUT[j]) continue;
      dp[j] -= tot;
      if (dp[j] < 0) {
        goOUT[j] = 1;
        tot += d[j];
      }
      if (r <= v[i]) tot--;
      r++;
    }
  }
  vector<int> rs;
  for (int i = 0; i < n; i++)
    if (!goOUT[i]) rs.push_back(i + 1);
  cout << int((rs).size()) << endl;
  for (int i = 0; i < int((rs).size()); i++) cout << rs[i] << " ";
  return 0;
}
