#include <bits/stdc++.h>
using namespace std;
int G[26][26];
int visit[26];
int main() {
  int n, i, j, k;
  while (~scanf("%d", &n)) {
    char pre[105] = "";
    char cur[105] = "";
    int flag = 1;
    vector<int> ans;
    memset(G, 0, sizeof(G));
    memset(visit, 0, sizeof(visit));
    for (i = 0; i < n; i++) {
      scanf("%s", cur);
      if (i) {
        for (j = 0; cur[j] && pre[j] && cur[j] == pre[j]; j++) {
          ;
        }
        if (!cur[j]) {
          flag = 0;
        } else if (pre[j]) {
          G[cur[j] - 'a'][pre[j] - 'a'] = 1;
        }
      }
      strcpy(pre, cur);
    }
    for (i = 0; i < 26; i++) {
      for (j = 0; j < 26; j++) {
        if (!visit[j]) {
          int flag_t = 1;
          for (k = 0; k < 26; k++) {
            if (G[k][j] && !visit[k]) {
              flag_t = 0;
            }
          }
          if (flag_t) {
            visit[j] = 1;
            ans.push_back(j + 'a');
            break;
          }
        }
      }
    }
    if (flag && ans.size() == 26) {
      for (i = 25; i >= 0; i--) {
        putchar(ans[i]);
      }
      putchar('\n');
    } else {
      printf("%s\n", "Impossible");
    }
  }
  return 0;
}
