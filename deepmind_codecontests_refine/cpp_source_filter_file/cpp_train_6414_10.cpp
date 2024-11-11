#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > v1[3 * 100009];
vector<pair<pair<int, int>, int> > v2[3 * 100009];
vector<pair<int, int> > crd;
vector<int> ans(100009);
int main() {
  int n, w, h;
  scanf("%d%d%d", &n, &w, &h);
  crd.push_back(pair<int, int>(0, 0));
  for (int i = 1; i <= n; ++i) {
    int g;
    pair<int, int> e;
    scanf("%d%d%d", &g, &e.first, &e.second);
    if (g >> 1) {
      crd.push_back(pair<int, int>(w, e.first));
      v2[w + h - e.first + e.second].push_back(pair<pair<int, int>, int>(e, i));
    } else {
      crd.push_back(pair<int, int>(e.first, h));
      v1[w + h - e.first + e.second].push_back(pair<pair<int, int>, int>(e, i));
    }
  }
  for (int i = 1; i < 2 * 100009; ++i) {
    sort(v1[i].begin(), v1[i].end(),
         [=](pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
           return p1.first.first < p2.first.first;
         });
    sort(v2[i].begin(), v2[i].end(),
         [=](pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
           return p1.first.first < p2.first.first;
         });
  }
  for (int i = 1; i < 2 * 100009; ++i) {
    int s1 = v1[i].size();
    int s2 = v2[i].size();
    for (int j = 0; j < s1; ++j) {
      int u = s1 - j - 1;
      if (u < s2) {
        ans[v1[i][j].second] = v2[i][u].second;
      } else {
        ans[v1[i][j].second] = v1[i][s2 + j].second;
      }
    }
    for (int j = 0; j < s2; ++j) {
      int u = s2 - j - 1;
      if (u < s1) {
        ans[v2[i][j].second] = v1[i][u].second;
      } else {
        ans[v2[i][j].second] = v2[i][s1 + j].second;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d %d\n", crd[ans[i]].first, crd[ans[i]].second);
  }
  return 0;
}
