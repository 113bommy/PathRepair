#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s[n + 1];
  for (int i = 0; i <= n; ++i) s[i] = 0;
  int u, v;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    ++s[u];
    ++s[v];
  }
  for (int i = 0; i <= n; ++i) {
    if (s[i] == 2) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
