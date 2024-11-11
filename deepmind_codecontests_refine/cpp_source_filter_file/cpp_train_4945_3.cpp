#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
vector<int> v[200005];
set<pair<int, int>> s;
int total, cl, seg[400005], num[200005], to[200005];
bool ans[200005], vis1[200005], vis[200005];
int main() {
  scanf("%d%d", &total, &cl);
  for (int i = 1; i <= total; i++) {
    int k;
    scanf("%d", &k);
    num[i] = k;
    for (int j = 0; j < k; j++) {
      int a, h;
      scanf("%d", &a);
      h = a;
      if (a < 0) h = cl - a;
      if (seg[h]) {
        if (h <= cl)
          vis[h] = 1;
        else
          vis[h - cl] = 1;
        if (h <= total) ans[h] = 1;
        vis1[seg[h]] = vis1[i] = 1;
      } else
        seg[h] = i;
      v[i].push_back(a);
    }
  }
  for (int i = 1; i <= total; i++)
    if (!vis1[i]) s.insert(make_pair(num[i], i));
  while (s.size() && s.begin()->first) {
    int id = s.begin()->second;
    s.erase(s.begin());
    for (int i = 0; i < v[id].size(); i++)
      if (!vis[abs(v[id][i])]) {
        int k = v[id][i], in = abs(k);
        vis[in] = 1;
        ans[in] = k > 0;
        int o;
        if (k > 0)
          o = seg[cl + k];
        else
          o = seg[-k];
        set<pair<int, int>>::iterator it = s.find(make_pair(num[o], o));
        if (it != s.end()) {
          num[o]--;
          s.erase(it);
          s.insert(make_pair(num[o], o));
        }
        break;
      }
  }
  if (s.size())
    printf("NO");
  else {
    printf("YES\n");
    for (int i = 1; i <= cl; i++) printf("%d", ans[i]);
  }
  return 0;
}
