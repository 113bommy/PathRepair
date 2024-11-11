#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
pair<int, int> a[4];
int main() {
  int i, j, k, l;
  int T;
  cin >> T;
  while (T--) {
    for (i = 0; i < 4; i++) cin >> a[i].first >> a[i].second;
    vector<int> pd;
    for (i = 0; i < 4; i++) {
      for (j = i + 1; j < 4; j++)
        pd.push_back(abs(a[j].first - a[i].first)),
            pd.push_back(abs(a[j].second - a[i].second));
    }
    sort((pd).begin(), (pd).end());
    pd.erase(unique((pd).begin(), (pd).end()), pd.end());
    int ans = 0x3f3f3f3f;
    map<pair<int, int>, pair<int, int> > ansmq;
    for (i = 0; i < 24; i++) {
      for (auto d : pd) {
        if (d == 0) continue;
        vector<int> px, py;
        for (j = 0; j < 4; j++) {
          px.push_back(a[j].first);
          px.push_back(a[j].first + d);
          px.push_back(a[j].first - d);
          py.push_back(a[j].second);
          py.push_back(a[j].second + d);
          py.push_back(a[j].second - d);
        }
        vector<int> xu, yu;
        for (j = 0; j < 4; j++)
          xu.push_back(j % 2 ? a[j].first - d : a[j].first),
              yu.push_back(j >= 2 ? a[j].second - d : a[j].second);
        sort((xu).begin(), (xu).end()), sort((yu).begin(), (yu).end());
        px.push_back((xu[0] + xu[3]) / 2);
        py.push_back((yu[0] + yu[3]) / 2);
        sort((px).begin(), (px).end()), sort((py).begin(), (py).end());
        px.erase(unique((px).begin(), (px).end()), px.end());
        py.erase(unique((py).begin(), (py).end()), py.end());
        for (auto x : px) {
          for (auto y : py) {
            pair<int, int> b[4];
            b[0] = pair<int, int>(x, y);
            b[1] = pair<int, int>(x + d, y);
            b[2] = pair<int, int>(x, y + d);
            b[3] = pair<int, int>(x + d, y + d);
            int ma = -1;
            for (j = 0; j < 4; j++) {
              if (b[j].first != a[j].first && b[j].second != a[j].second) break;
              ma = max(ma, max(abs(a[j].first - b[j].first),
                               abs(a[j].second - b[j].second)));
            }
            if (j != 4) continue;
            if (ma < ans) {
              ans = ma;
              ansmq.clear();
              for (j = 0; j < 4; j++) ansmq[a[j]] = b[j];
            }
          }
        }
      }
      next_permutation(a, a + 4);
    }
    if (ans == 0x3f3f3f3f)
      printf("-1\n");
    else {
      printf("%d\n", ans);
      for (i = 0; i < 4; i++)
        printf("%d %d\n", ansmq[a[i]].first, ansmq[a[i]].second);
    }
  }
  return 0;
}
