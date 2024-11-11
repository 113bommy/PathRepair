#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ja, jd;
  vector<int> c(m);
  for (int i = 0; i < n; i++) {
    string s;
    int j;
    cin >> s >> j;
    if (s == "ATK")
      ja.push_back(j);
    else
      jd.push_back(j);
  }
  for (int i = 0; i < m; i++) cin >> c[i];
  sort(c.rbegin(), c.rend());
  sort(ja.begin(), ja.end());
  sort(jd.begin(), jd.end());
  int sum = 0;
  for (int i = 0; i < min(ja.size(), c.size()); i++) {
    if (c[i] - ja[i] > 0) sum += c[i] - ja[i];
  }
  int res = sum;
  if (m > n) {
    sort(c.begin(), c.end());
    bool ok = true;
    for (int i = 0; i < jd.size(); i++) {
      ok = false;
      for (int j = 0; j < c.size(); j++) {
        if (c[j] > jd[i]) {
          c.erase(c.begin() + j);
          ok = true;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) {
      int s = 0;
      for (int i = 0; i < ja.size(); i++) {
        ok = false;
        for (int j = 0; j < c.size(); j++) {
          if (c[j] > ja[i]) {
            s += c[j] - ja[i];
            c.erase(c.begin() + j);
            ok = true;
            break;
          }
        }
        if (!ok) break;
      }
      for (int i = 0; i < c.size(); i++) s += c[i];
      if (ok) res = max(res, s);
    }
  }
  cout << res << endl;
}
