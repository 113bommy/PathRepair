#include <bits/stdc++.h>
using namespace std;
bool can[26];
int n, m, k, q, res = 0;
char s[31][31];
char ss[1000000];
vector<pair<int, int>> ch[26], sh;
inline int dist(int i, int j, int shr, int shc) {
  return (i - shr) * (i - shr) + (j - shc) * (j - shc);
}
inline bool check(int i, int j) {
  for (int w = 0; w < sh.size(); w++) {
    int dis = dist(i, j, sh[w].first, sh[w].second);
    if (dis <= k * k) return true;
  }
  return false;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'S')
        sh.push_back(make_pair(i, j));
      else
        ch[s[i][j] - 'a'].push_back(make_pair(i, j));
    }
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < ch[i].size() && !can[i]; j++) {
      can[i] = can[i] | check(ch[i][j].first, ch[i][j].second);
    }
  scanf("%d%s", &q, ss);
  for (int i = 0; i < q; i++) {
    if (islower(ss[i])) {
      if (ch[ss[i] - 'a'].empty()) {
        res = -1;
        break;
      }
    } else {
      ss[i] = tolower(ss[i]);
      if (sh.empty() || ch[ss[i] - 'a'].empty()) {
        res = -1;
        break;
      }
      if (!can[ss[i] - 'a']) ++res;
    }
  }
  printf("%d", res);
  return 0;
}
