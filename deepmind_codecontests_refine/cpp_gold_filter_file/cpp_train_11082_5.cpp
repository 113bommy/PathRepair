#include <bits/stdc++.h>
using namespace std;
set<pair<int, pair<int, int> > > S;
set<pair<int, pair<int, int> > >::iterator it;
pair<int, int> l[200001];
vector<pair<int, int> > ans;
int a[200001], tag[200001], n;
char s[200001];
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++) s[i] = (s[i] == 'B' ? 0 : 1);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    l[i] = pair<int, int>(i - 1, i + 1);
    if (i != n - 1 && s[i] ^ s[i + 1] == 1)
      S.insert(make_pair(abs(a[i] - a[i + 1]), pair<int, int>(i, i + 1)));
  }
  while (!S.empty()) {
    it = S.begin();
    pair<int, pair<int, int> > SV = *it;
    if (tag[SV.second.first] != 1 && tag[SV.second.second] != 1) {
      tag[SV.second.first] = tag[SV.second.second] = 1;
      ans.push_back(pair<int, int>(SV.second.first, SV.second.second));
      int x1 = l[SV.second.first].first, x2 = l[(*it).second.second].second;
      if (x1 != -1) l[x1].second = x2;
      if (x2 != n) l[x2].first = x1;
      if (x1 != -1 && x2 != n && (s[x1] ^ s[x2] == 1))
        S.insert(make_pair(abs(a[x1] - a[x2]), pair<int, int>(x1, x2)));
    }
    S.erase(it);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  return 0;
}
