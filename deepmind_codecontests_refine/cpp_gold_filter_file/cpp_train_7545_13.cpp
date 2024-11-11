#include <bits/stdc++.h>
using namespace std;
vector<int> e[100001];
int n, m, k, x, y, w, t[100001], d[100001], v[100001], s[100001];
double l, r, mid;
void del(int x) {
  v[x] = 0;
  s[x] = 0;
  w--;
  for (int i = (0); i <= (d[x] - 1); i++) {
    int tt = e[x][i];
    if (v[tt]) {
      s[tt]--;
      if (d[tt] * mid > s[tt]) del(tt);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (1); i <= (k); i++) {
    scanf("%d", &x);
    t[x] = 1;
  }
  for (int i = (1); i <= (m); i++) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    d[x]++;
    e[y].push_back(x);
    d[y]++;
  }
  l = 0;
  r = 1;
  mid = (l + r) / 2;
  for (; r - l > 1e-9; mid = (l + r) / 2) {
    for (int i = (1); i <= (n); i++) v[i] = 1 - t[i], s[i] = 0;
    w = 0;
    for (int i = (1); i <= (n); i++)
      if (v[i]) {
        w++;
        for (int j = (0); j <= (d[i] - 1); j++)
          if (v[e[i][j]]) s[i]++;
      }
    for (int i = (1); i <= (n); i++)
      if (v[i])
        if (d[i] * mid > s[i]) del(i);
    if (!w)
      r = mid;
    else
      l = mid;
  }
  mid -= 1e-9;
  for (int i = (1); i <= (n); i++) v[i] = 1 - t[i], s[i] = 0;
  w = 0;
  for (int i = (1); i <= (n); i++)
    if (v[i]) {
      w++;
      for (int j = (0); j <= (d[i] - 1); j++)
        if (v[e[i][j]]) s[i]++;
    }
  for (int i = (1); i <= (n); i++)
    if (v[i])
      if (d[i] * mid > s[i]) del(i);
  printf("%d\n", w);
  for (int i = (1); i <= (n); i++)
    if (v[i]) printf("%d ", i);
  printf("\n");
}
