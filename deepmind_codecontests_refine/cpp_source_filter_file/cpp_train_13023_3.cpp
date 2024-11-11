#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
int n, i, j, k, t;
int par[5];
int tot[5];
int deg[5];
int cnt[5][5];
int mini[5][5];
int cc;
int find_set(int v) {
  if (par[v] == v) return v;
  return par[v] = find_set(par[v]);
}
void union_set(int a, int b, int c) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    par[b] = a;
    tot[a] += tot[b];
    cc--;
  }
  tot[a] += c;
}
int main() {
  memset(tot, 0, sizeof tot);
  scanf("%d", &n);
  for (i = 1; i <= 4; ++i) par[i] = i;
  cc = 4;
  int mi = 1e5;
  for (i = 1; i <= 4; ++i) {
    for (j = 1; j <= 4; ++j) {
      mini[i][j] = 1e6;
    }
  }
  for (i = 0; i < n; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &c, &b);
    union_set(a, b, c);
    if (a != b) {
      deg[a]++;
      deg[b]++;
      cnt[a][b]++;
      cnt[b][a]++;
      mini[a][b] = mini[b][a] = min(mini[a][b], c);
      mi = min(mi, c);
    }
  }
  if (cc != 1)
    printf("%d\n", *max_element(tot + 1, tot + 5));
  else {
    bool del = true;
    for (i = 1; i <= 4; ++i)
      if (deg[i] % 2 == 0) del = false;
    int top = find_set(1);
    if (del) {
      int minmin = 1e6;
      for (i = 1; i <= 4; ++i) {
        if (deg[1] < 2) continue;
        for (j = 1; j <= 4; ++j) {
          if (i == j || deg[j] < 2) continue;
          minmin = min(minmin, mini[i][j]);
        }
      }
      if (minmin <= 1e5) mi = minmin;
    }
    printf("%d\n", tot[top] - (del ? mi : 0));
  }
  return 0;
}
