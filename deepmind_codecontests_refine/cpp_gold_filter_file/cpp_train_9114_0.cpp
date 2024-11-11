#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > s1;
vector<pair<int, pair<int, int> > > s2;
int match[200010];
int use[200010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    s1.push_back(make_pair(a, i));
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a);
    int num = 0;
    while (1) {
      s2.push_back(make_pair(a, make_pair(-num, i)));
      if (a == 1) break;
      num++;
      a = a / 2 + a % 2;
    }
  }
  int ans = 0;
  int num = 0;
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  int st = (int)s1.size() - 1;
  memset(use, -1, sizeof(use));
  for (int i = (int)s2.size() - 1; i >= 0; i--) {
    while (st && s1[st].first > s2[i].first) st--;
    if (st < 0) break;
    if (s1[st].first == s2[i].first && use[s2[i].second.second] == -1) {
      ans++;
      num -= s2[i].second.first;
      match[s1[st].second] = s2[i].second.second;
      use[s2[i].second.second] = -s2[i].second.first;
      st--;
    }
  }
  printf("%d %d\n", ans, num);
  for (int i = 1; i <= m; i++) printf("%d ", max(0, use[i]));
  printf("\n");
  for (int i = 1; i <= n; i++) printf("%d ", match[i]);
  printf("\n");
  return 0;
}
