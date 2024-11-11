#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e18;
const long long inf = 1e18;
const double eps = 1e-8;
const double pi = acos(-1);
int p[5020];
int dp[5030];
vector<int> v[5030];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    if (d > (n * (n - 1) / 2)) {
      cout << "NO\n";
      continue;
    }
    int dep = 0;
    for (int i = 2; i < n + 1; i++) {
      p[i] = i - 1;
      dp[i] = i - 1;
      dep += i - 1;
    }
    int k = n, tmp = 0;
    v[tmp].push_back(1);
    int flog = 0;
    while (dep > d) {
      if (k == 1) {
        flog = 1;
        break;
      }
      if (v[tmp].size() == (1 << tmp)) {
        tmp++;
        v[tmp].push_back(tmp + 1);
      }
      if (dp[k] - tmp > dep - d) {
        tmp = dp[k] - (dep - d);
        if (!v[tmp].size()) v[tmp].push_back(tmp + 1);
        if (!v[tmp - 1].size()) v[tmp - 1].push_back(tmp);
      }
      int sz = v[tmp].size();
      v[tmp].push_back(k);
      dep -= dp[k];
      dep += tmp;
      dp[k] = tmp;
      p[k] = v[tmp - 1][sz / 2];
      k--;
    }
    if (flog) {
      cout << "NO\n";
      for (int i = 0; i < k + 3; i++) v[i].clear();
      continue;
    }
    cout << "YES\n";
    for (int i = 2; i < n + 1; i++) cout << p[i] << ' ';
    cout << '\n';
    for (int i = 0; i < k + 3; i++) v[i].clear();
  }
  return 0;
}
