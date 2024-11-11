#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
const int maxN = 1e5 + 5;
int N;
int f[maxN];
void init() {
  scanf("%d", &N);
  for (int i = (1), _end = (N); i <= _end; ++i) {
    scanf("%d", &f[i]);
  }
}
bool vis[maxN];
pair<int, int> Cycle[maxN];
int tot;
void solve() {
  for (int i = (1), _end = (N); i <= _end; ++i) {
    if (vis[i] == false) {
      Cycle[++tot].second = i;
      int cur = i;
      while (vis[cur] == false) {
        Cycle[tot].first++;
        vis[cur] = true;
        cur = f[cur];
      }
    }
  }
  sort(Cycle + 1, Cycle + tot + 1);
  if (Cycle[1].first == 1) {
    puts("YES");
    for (int i = (1), _end = (N); i <= _end; ++i)
      if (Cycle[i].second != i) printf("%d %d\n", Cycle[1].second, i);
    return;
  } else if (Cycle[1].first == 2) {
    bool flag = true;
    for (int i = (2), _end = (tot); i <= _end; ++i)
      if (Cycle[i].first % 2) {
        flag = false;
        break;
      }
    if (flag == false) {
      puts("NO");
      return;
    }
    puts("YES");
    printf("%d %d\n", Cycle[1].second, f[Cycle[1].second]);
    memset(vis, 0, sizeof(vis));
    vis[Cycle[1].second] = vis[f[Cycle[1].second]] = true;
    for (int i = (1), _end = (N); i <= _end; ++i) {
      if (vis[i] == false) {
        int cur = i, cnt = 0;
        while (vis[cur] == false) {
          vis[cur] = true;
          if (++cnt % 2)
            printf("%d %d\n", Cycle[1].second, cur);
          else
            printf("%d %d\n", f[Cycle[1].second], cur);
          cur = f[cur];
        }
      }
    }
    return;
  }
  puts("NO");
}
int main() {
  init();
  solve();
  return 0;
}
