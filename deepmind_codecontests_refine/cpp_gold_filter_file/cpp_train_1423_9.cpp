#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int n, id[5050], idtop = 0, ans[5050];
bool app[5050];
map<int, int> M;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, res = 1;
    scanf("%d", &x);
    if (x == 0) {
      id[i] = 0;
      continue;
    }
    for (int j = 2; j * j <= abs(x); j++)
      if (x % j == 0) {
        int cnt = 0;
        while (x % j == 0) x /= j, cnt++;
        if (cnt % 2) res *= j;
      }
    if (abs(x) != 1) res *= abs(x);
    if (x < 0) res *= -1;
    if (M.count(res))
      id[i] = M[res];
    else
      id[i] = (M[res] = ++idtop);
  }
  for (int i = 1; i <= n; i++) {
    memset(app, 0, sizeof(app));
    int cnt = 0;
    for (int j = i; j <= n; j++) {
      if (id[j]) {
        if (!app[id[j]]) cnt++;
        app[id[j]] = true;
        ans[cnt]++;
      } else {
        if (cnt == 0)
          ans[1]++;
        else
          ans[cnt]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}
