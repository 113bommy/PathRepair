#include <bits/stdc++.h>
using namespace std;
int chh;
const int N = 26, LEN = 200005;
int p[LEN], vis[LEN];
string s1, s2;
vector<int> q[N];
int main() {
  int i, j, k, h, l1, l2;
  bool flag;
  while (cin >> s1 >> s2) {
    l1 = s1.size(), l2 = s2.size();
    for (i = 0; i < N; i++) q[i].clear();
    for (i = 0; i < l1; i++) q[s1[i] - 'a'].push_back(i);
    if (q[s2[0] - 'a'].empty()) {
      puts("No");
      continue;
    }
    p[0] = 0;
    flag = 1;
    for (i = 1; i < l2; i++) {
      j = s2[i] - 'a';
      k = s2[i - 1] - 'a';
      p[i] =
          upper_bound(q[j].begin(), q[j].end(), q[k][p[i - 1]]) - q[j].begin();
      if (p[i] == q[j].size()) {
        flag = 0;
        break;
      }
    }
    if (!flag) {
      puts("No");
      continue;
    }
    memset(vis, 0, sizeof(vis));
    for (i = l2 - 1; i >= 0; i--) {
      j = s2[i] - 'a';
      if (i == l2 - 1) {
        for (k = p[i]; k < q[j].size(); k++) {
          if (vis[q[j][k]] == 1) break;
          vis[q[j][k]] = 1;
        }
        p[i] = q[j].size() - 1;
      } else {
        k = s2[i + 1] - 'a';
        h = lower_bound(q[j].begin(), q[j].end(), q[k][p[i + 1]]) -
            q[j].begin();
        for (k = p[i]; k < h; k++) {
          if (vis[q[j][k]] == 1) break;
          vis[q[j][k]] = 1;
        }
        p[i] = h - 1;
      }
    }
    flag = 1;
    for (i = 0; i < l1 && flag; i++) {
      if (!vis[i]) flag = 0;
    }
    flag ? puts("Yes") : puts("No");
  }
  return 0;
}
