#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > vec[300000 + 10];
int ch[300000 + 10];
vector<int> e;
int main() {
  int n, t;
  scanf("%d", &t);
  while (t--) {
    int m, n3, u, v, cnt = 0, ix;
    scanf("%d %d", &n, &m);
    n3 = n * 3;
    for (int i = 1; i <= n3; i++) vec[i].clear(), ch[i] = false;
    for (int i = 1; i <= m; i++) {
      scanf("%d %d", &u, &v);
      vec[u].push_back(make_pair(v, i));
      vec[v].push_back(make_pair(u, i));
    }
    e.clear();
    for (int i = 1; i <= n3; i++)
      for (pair<int, int> nxt : vec[i]) {
        v = nxt.first;
        ix = nxt.second;
        if (v >= i) continue;
        if (ch[v] == false) {
          ch[i] = ch[v] = true;
          e.push_back(ix);
          break;
        }
      }
    if (e.size() >= n) {
      printf("Matching\n");
      for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", e[i]);
      }
      printf("\n");
    } else {
      printf("IndSet\n");
      for (int i = 1; i <= n3; i++)
        if (ch[i] == false) {
          if (cnt) printf(" ");
          printf("%d", i);
          cnt++;
          if (cnt == n) break;
        }
      printf("\n");
    }
  }
  return 0;
}
