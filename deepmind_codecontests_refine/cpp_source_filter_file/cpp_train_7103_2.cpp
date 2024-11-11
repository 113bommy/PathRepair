#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
vector<int> b[100001];
int x[100001];
int main() {
  int q, w, e, n, t, f, res, k, r[31], itog, z;
  cin >> t;
  for (q = 1; q <= t; q++) x[q] = 0;
  for (q = 1; q <= t; q++) {
    cin >> n >> k;
    cin >> s;
    for (e = 1; e <= n / k; e++) {
      for (w = 1; w <= k / 2; w++) a.push_back(w);
      for (w = k / 2 + 1; w <= k; w++) a.push_back(k - w + 1);
    }
    z = 0;
    for (w = 0; w < n; w++) b[a[w]].push_back(w);
    for (w = 0; w <= k / 2 + 1; w++) {
      for (e = 1; e <= 30; e++) r[e] = 0;
      for (e = 0; e < b[w].size(); e++) r[char(s[b[w][e]]) - 96]++;
      res = 0;
      itog = 0;
      for (e = 1; e <= 30; e++) {
        if (res < r[e]) res = r[e];
        itog = itog + r[e];
      }
      z = z + itog - res;
    }
    x[q] = z;
    a.clear();
    for (w = 0; w < k; w++) b[w].clear();
  }
  for (q = 1; q <= t; q++) cout << x[q] << endl;
  return 0;
}
