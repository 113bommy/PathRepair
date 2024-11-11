#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
set<int> st[maxn], ts[maxn];
int flag[maxn];
bool vis[maxn];
int n, m;
int tot;
int p[maxn];
void init() {
  tot = 0;
  memset(flag, 0, sizeof(flag));
  for (int i = 2; i <= 100000; i++) {
    if (!flag[i]) p[++tot] = i;
    for (int j = 2 * i; j <= 100000; j += i) {
      flag[j] = 1;
    }
  }
  for (int i = 1; i <= 100000; i++) {
    ts[i].clear();
    int tmp = i;
    for (int j = 1; j <= tot; j++) {
      if (tmp % p[j] == 0) {
        ts[i].insert(p[j]);
        while (tmp % p[j] == 0) {
          tmp /= p[j];
        }
        if (tmp == 1) break;
        if (flag[tmp] == 0) {
          ts[i].insert(tmp);
          break;
        }
      }
    }
  }
}
int main() {
  init();
  while (scanf("%d%d", &n, &m) != EOF) {
    char op[5];
    int num;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= tot; i++) st[p[i]].clear();
    for (int i = 0; i < m; i++) {
      scanf("%s%d", op, &num);
      if (op[0] == '+') {
        if (vis[num])
          printf("Already on\n");
        else {
          int f = 0, pr = -1;
          for (set<int>::iterator it = ts[num].begin(); it != ts[num].end();
               it++) {
            if (!st[*it].empty()) {
              f = 1;
              pr = *it;
            }
          }
          if (f) {
            printf("Conflict with %d\n", *st[pr].begin());
          } else {
            printf("Success\n");
            vis[num] = true;
            for (set<int>::iterator it = ts[num].begin(); it != ts[num].end();
                 it++) {
              st[*it].insert(num);
            }
          }
        }
      } else {
        if (!vis[num]) {
          printf("Already off\n");
        } else {
          printf("Success\n");
          vis[num] = false;
          for (set<int>::iterator it = ts[num].begin(); it != ts[num].end();
               it++) {
            st[*it].erase(num);
          }
        }
      }
    }
  }
  return 0;
}
