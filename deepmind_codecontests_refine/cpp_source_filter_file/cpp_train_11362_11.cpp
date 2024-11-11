#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int T, n, d[N];
vector<int> e[N];
char s[N];
int main() {
  scanf("%d", &T);
  for (; T; --T) {
    scanf("%d", &n);
    for (int i = 1; i <= n + n; i++) e[i].clear(), d[i] = 0;
    for (int i = 1, x, y; i < n; i++)
      scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x), ++d[x],
          ++d[y];
    scanf("%s", s + 1);
    if (n < 3) {
      puts("Draw");
      continue;
    }
    if (n == 3) {
      int cnt = 0;
      for (int i = 1; i <= n; i++)
        if (s[i] == 'W') ++cnt;
      puts(cnt >= 2 ? "White" : "Draw");
      continue;
    }
    for (int i = 1; i <= n; i++)
      if (s[i] == 'W') {
        ++n, e[i].push_back(n), e[n].push_back(i), d[n] = 3;
      }
    bool ans = 0;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      if (d[i] >= 4) {
        ans = 1;
        break;
      }
      if (d[i] == 3) {
        ++tot;
        int cnt = 0;
        for (auto v : e[i])
          if (d[v] > 1) ++cnt;
        if (cnt > 1) {
          ans = 1;
          break;
        }
      }
    }
    if (tot == 2 && n % 2) ans = 1;
    puts(ans ? "White" : "Draw");
  }
  return 0;
}
