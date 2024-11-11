#include <bits/stdc++.h>
using namespace std;
int T, n, m, a[2010], fr[2010], d[2010][2010];
char S[2010];
bool v[2010];
bitset<2010> t[2010], r[2010];
vector<int> e[2010];
int ck(int t, int x) {
  int y = 1;
  v[x] = 1;
  for (auto i : e[x])
    if (!v[i] && r[t][i]) y += ck(t, i);
  return y;
}
void sol() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) {
    t[i].reset();
    e[i].clear();
  }
  for (int i = (1); i <= (m); i++) r[i].reset();
  for (int i = (1); i <= (m); i++) {
    scanf("%s", S + 1);
    int x = 0;
    for (int j = (1); j <= (n); j++)
      if (S[j] == '1') {
        x++;
        r[i][j] = 1;
      }
    if (x > 1)
      for (int j = (1); j <= (n); j++)
        if (S[j] == '1') t[j][i] = 1;
  }
  for (int i = (1); i <= (n); i++) v[i] = 0, a[i] = fr[i] = 0;
  a[1] = m;
  a[0] = -1;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (i != j) d[i][j] = (t[i] & t[j]).count();
  for (int i = (1); i <= (n); i++) {
    int x = 0;
    for (int j = (1); j <= (n); j++)
      if (!v[j] && a[j] > a[x]) x = j;
    v[x] = 1;
    for (int j = (1); j <= (n); j++)
      if (!v[j] && a[j] < d[x][j]) {
        a[j] = d[x][j];
        fr[j] = x;
      }
  }
  for (int i = (2); i <= (n); i++) {
    e[i].push_back(fr[i]);
    e[fr[i]].push_back(i);
  }
  for (int i = (1); i <= (m); i++) {
    for (int j = (1); j <= (n); j++) v[j] = 0;
    for (int j = (1); j <= (n); j++)
      if (r[i][j]) {
        if (ck(i, j) != r[i].count()) {
          printf("NO\n");
          return;
        }
        break;
      }
  }
  printf("YES\n");
  for (int i = (2); i <= (n); i++) printf("%d %d\n", fr[i], i);
}
int main() {
  for (scanf("%d", &T); T; T--) sol();
}
