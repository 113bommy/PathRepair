#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> b(n), a(n);
  vector<vector<long long> > c(60);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &b[i]);
    c[63 - __builtin_clzll(b[i])].push_back(b[i]);
  }
  long long now = 0;
  for (int i = 0; i < n; i++) {
    bool ok = 0;
    for (int j = 0; j < 60; j++) {
      if ((now >> j & 1) || c[j].empty()) continue;
      now ^= a[i] = c[j].back();
      c[j].pop_back();
      ok = 1;
      break;
    }
    if (!ok) return cout << "No\n", 0;
  }
  cout << "Yes\n";
  for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
  return 0;
}
