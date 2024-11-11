#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9 + 7;
const int MAX = (int)1e4 + 1;
const int mod = (int)1e9 + 9;
int main(void) {
  int n;
  while (cin >> n) {
    int tg = (n + 1) / 2;
    map<int, pair<int, int> > m;
    for (int i = 0; i < n; i++) {
      int fr, s;
      scanf("%d%d", &fr, &s);
      if (fr == s)
        m[fr].first++;
      else {
        m[s].second++;
        m[fr].first++;
      }
    }
    int res = OO;
    for (auto it = m.begin(); it != m.end(); it++) {
      int ff = it->second.first, ss = it->second.second;
      if (ff + ss >= tg) res = min(res, max(0, tg - ff));
    }
    if (res == OO)
      cout << "-1\n";
    else
      cout << res << "\n";
  }
  return 0;
}
