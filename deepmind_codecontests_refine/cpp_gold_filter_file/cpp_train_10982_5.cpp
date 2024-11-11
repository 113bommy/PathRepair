#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
const double eps = 1e-7;
const double pi = acos(-1.0);
const long long INF = (long long)2e9 + 1;
const long long LINF = (long long)8e18;
const long long inf = (long long)2e9 + 1;
const long long linf = (long long)8e18;
const long long MM = (long long)1e9 + 7;
int solve();
void gen();
int main() {
  solve();
  return 0;
}
int f[1007];
int solve() {
  int n;
  cin >> n;
  for (int i = 2; i < (long long)n + 1; i++) f[i] = 1;
  vector<int> ans;
  for (int i = 0; i < (int)n + 1; i++)
    if (f[i]) {
      for (int j = i * i; j <= n; j += i) f[j] = 0;
      ans.push_back(i);
    }
  for (int i = 0; i < (int)n + 1; i++) {
    if (!f[i]) continue;
    long long cur = i * i;
    while (cur <= n) {
      ans.push_back(cur);
      cur *= i;
    }
  }
  cout << ans.size() << "\n";
  for (int v : ans) cout << v << " ";
  return 0;
}
