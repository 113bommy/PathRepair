#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  vector<int> g(n + 1, 0);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a]++;
    g[b]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i] < 2) ans++;
  }
  cout << ans;
  return 0;
}
