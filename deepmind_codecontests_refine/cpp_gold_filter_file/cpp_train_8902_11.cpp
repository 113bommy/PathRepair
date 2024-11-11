#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  bool vis[n];
  memset(vis, 0, sizeof(vis));
  int ps = 0;
  while (true) {
    if (vis[ps]) {
      cout << "INFINITE";
      return 0;
    }
    vis[ps] = 1;
    if (s[ps] == '<')
      ps -= a[ps];
    else
      ps += a[ps];
    if (ps < 0 || ps >= n) {
      cout << "FINITE";
      return 0;
    }
  }
}
