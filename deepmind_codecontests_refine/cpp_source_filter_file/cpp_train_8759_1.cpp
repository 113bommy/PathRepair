#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans, res, p = INT_MAX;
  cin >> n;
  string s, t;
  cin >> s;
  string g = "ACTG";
  for (int i = 0; i < int(n - 3); i++) {
    t = s.substr(i, 4);
    ans = 0;
    for (int j = 0; j < int(4); j++) {
      if (t[j] < g[j])
        res = min(g[j] - t[j], t[j] - g[j] + 26);
      else
        res = min(t[j] - g[j], g[j] - t[j] + 26);
      ans += res;
    }
  }
  p = min(p, ans);
  cout << p << "\n";
}
