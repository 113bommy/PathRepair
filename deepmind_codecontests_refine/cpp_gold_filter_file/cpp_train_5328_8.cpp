#include <bits/stdc++.h>
using namespace std;
int q, n, k;
int mark[101][5051];
int f[101][5051], g[101][5051];
vector<pair<int, int> > v;
int c[1005][105];
int ls[1005], rs[1005], tot;
void solve(int &p, int a, int b) {
  p = ++tot;
  if (mark[a][b] == 2) {
    for (int i = 1; i <= a; i++) c[p][i] = i;
    return;
  }
  if (mark[a][b] == 3) {
    if (a & 1) {
      for (int i = 1; i + i < a; i++)
        c[p][i] = i + i, c[p][a - i + 1] = i + i + 1;
      c[p][a / 2 + 1] = 1;
    } else {
      for (int i = 1; i + i <= a; i++)
        c[p][i] = i + i, c[p][i + (a >> 1)] = i + i - 1;
    }
    return;
  }
  int a1 = f[a][b], b1 = g[a][b], a2 = a + 1 - a1, b2 = b + 1 - b1;
  solve(ls[p], a1, b1);
  solve(rs[p], a2, b2);
  for (int i = 1; i <= a2; i++) c[p][i] = c[ls[p]][1] + c[rs[p]][i] - 1;
  for (int i = 2; i <= a1; i++) {
    if (c[ls[p]][i] > c[ls[p]][1])
      c[p][i + a2 - 1] = c[ls[p]][i] + a2 - 1;
    else
      c[p][i + a2 - 1] = c[ls[p]][i];
  }
  if (c[p][1] < min(c[p][a2], c[p][a2 + 1])) reverse(c[p] + 1, c[p] + a2 + 1);
  if (c[p][1] > max(c[p][a2], c[p][a2 + 1])) reverse(c[p] + 1, c[p] + a2 + 1);
}
int main() {
  cin >> q;
  mark[2][3] = 2, mark[3][6] = 2, mark[3][5] = 1, f[3][5] = 2, g[3][5] = 3;
  v.push_back(make_pair(2, 3));
  v.push_back(make_pair(3, 5));
  v.push_back(make_pair(3, 6));
  for (int i = 4; i <= 100; i++)
    mark[i][i + 1] = 3, mark[i][i * (i + 1) / 2] = 2;
  int cnt = 0;
  for (register int a = 4; a <= 100; a++) {
    int tot = a * (a + 1) / 2;
    v.push_back(make_pair(a, a + 1));
    for (register int b = a + 2; b < tot; b++) {
      cnt++;
      for (register int k = 0; k < v.size(); k++) {
        int a1 = v[k].first, b1 = v[k].second;
        int a2 = a + 1 - a1, b2 = b + 1 - b1;
        if (a2 > 0 && b2 > 0 && mark[a2][b2]) {
          f[a][b] = a1, g[a][b] = b1;
          mark[a][b] = 1;
          break;
        }
      }
    }
    v.push_back(make_pair(a, tot));
  }
  while (q--) {
    scanf("%d%d", &n, &k);
    if (n + k == 2) {
      puts("YES");
      puts("1");
      continue;
    }
    if (!mark[n][k]) {
      puts("NO");
      continue;
    }
    int p;
    tot = 0;
    solve(p, n, k);
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", c[1][i]);
    puts("");
  }
  return 0;
}
