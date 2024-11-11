#include <bits/stdc++.h>
using namespace std;
int n, m, v, c;
vector<int> ans;
vector<pair<int, int> > ma;
bool cal() {
  for (int i = 0; i < ma.size(); i++)
    for (int j = i + 1; j < ma.size(); j++) {
      if (ma[i].first >= ma[j].first && ma[i].second <= ma[j].second) {
        ma.erase(ma.begin() + j);
        return true;
      }
      if (ma[i].first <= ma[j].first && ma[i].second >= ma[j].second) {
        ma.erase(ma.begin() + i);
        return true;
      }
    }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &v, &c);
    if (v > c) swap(v, c);
    ma.push_back(make_pair(v, c));
  }
  while (cal())
    ;
  sort(ma.begin(), ma.end());
  int ne = -20000;
  for (int i = 0; i < ma.size(); i++) {
    if (ma[i].first > ne) ans.push_back(ma[i].second), ne = ma[i].second;
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}
