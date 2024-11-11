#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 7;
const int N = (int)1e5 + 7;
int skill[107], who[123];
char c[123];
int kb[1234567];
int f[1234567];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", skill + i);
  }
  sort(skill, skill + n, greater<int>());
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    char ch = getchar();
    if (ch != 'p' && ch != 'b') ch = getchar();
    c[i] = ch;
    scanf("%d", who + i);
  }
  kb[0] = 0;
  for (int t = 1; t < (1 << m); t++) {
    kb[t] = kb[t & (t - 1)] + 1;
  }
  f[(1 << m) - 1] = 0;
  for (int t = (1 << m) - 2; t >= 0; t--) {
    if (who[kb[t]] == 1) {
      f[t] = -inf;
      for (int i = 0; i < m; i++) {
        if (!(t & (1 << i))) {
          int ft = f[t + (1 << i)];
          if (c[kb[t]] == 'p') ft += skill[i];
          if (ft > f[t]) f[t] = ft;
        }
      }
    } else {
      f[t] = inf;
      for (int i = 0; i < m; i++) {
        if (!(t & (1 << i))) {
          int ft = f[t + (1 << i)];
          if (c[kb[t]] == 'p') ft -= skill[i];
          if (ft < f[t]) f[t] = ft;
        }
      }
    }
  }
  printf("%d", f[0]);
}
