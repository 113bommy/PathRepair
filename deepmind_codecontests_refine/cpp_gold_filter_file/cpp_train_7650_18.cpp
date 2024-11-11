#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int main() {
  int n = 0;
  bool f[10000];
  cin >> n;
  for (int i = 2; i <= n; ++i)
    if (!f[i])
      for (int q = i * 2; q <= n; q += i) f[q] = 1;
  for (int i = 2; i <= n; ++i)
    if (!f[i])
      for (int q = i; q <= n; q *= i) ans.push_back(q);
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
}
