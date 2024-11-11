#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0, m;
vector<int> g;
int main() {
  int a, b;
  cin >> n;
  for (int k = 1; k <= n; k++) {
    cin >> a;
    g.push_back(a);
  }
  sort(g.begin(), g.end());
  for (int k = 0; k <= n / 2; k++)
    if (g[k] + g[n - k - 1] == 3) {
      cnt++;
      g[k] = g[n - k] = 0;
    }
  int t = 0;
  for (int k = 0; k < n; k++) {
    if (g[k] == 2) {
      cout << cnt;
      return 0;
    } else
      t += g[k];
  }
  cout << cnt + t / 3;
  return 0;
}
