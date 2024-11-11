#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
const int N = 110000;
const int M = 5000;
const int oo = 10000 * 10000 * 10;
char a[N];
char b[N];
char ans[N];
int len, n;
int g[500][500];
int solve() {
  int i, j, k;
  len = strlen(a);
  if (strlen(b) != len) return -1;
  int sum = 0;
  for (i = 0; i < len; ++i) {
    if (a[i] == b[i]) continue;
    int cost = oo;
    int dex;
    for (j = 'a'; j <= 'z'; ++j) {
      if (g[a[i]][j] + g[b[i]][j] < cost) {
        dex = j;
        cost = g[a[i]][j] + g[b[i]][j];
      }
    }
    if (cost == 00) return -1;
    sum += cost;
    a[i] = dex;
  }
  return sum;
}
int main() {
  int i, j, cas = 0;
  scanf("%s", a);
  scanf("%s", b);
  scanf("%d", &n);
  for (i = 'a'; i <= 'z'; ++i)
    for (j = 'a'; j <= 'z'; ++j) {
      g[i][j] = oo;
      if (i == j) g[i][j] = 0;
    }
  char u, v;
  int c;
  for (i = 0; i < n; ++i) {
    while (getchar() != 10)
      ;
    scanf("%c %c %d", &u, &v, &c);
    g[u][v] = (g[u][v] < c ? g[u][v] : c);
  }
  for (int k = 'a'; k <= 'z'; ++k) {
    for (i = 'a'; i <= 'z'; ++i) {
      for (j = 'a'; j <= 'z'; ++j)
        g[i][j] = (g[i][j] < g[i][k] + g[k][j] ? g[i][j] : g[i][k] + g[k][j]);
    }
  }
  int ans = solve();
  if (ans == -1) {
    printf("%d\n", ans);
  } else {
    printf("%d\n", ans);
    printf("%s\n", a);
  }
  return 0;
}
