#include <bits/stdc++.h>
using namespace std;
const int nMax = 1010;
vector<int> e[nMax];
int n;
int s[2][nMax * 3];
int t[2], k[2];
void M(int *a, int x) {
  while (x < n * 3) {
    a[x]++;
    x += (x & (-x));
  }
}
int S(int *a, int x) {
  int res = 0;
  while (x) {
    res += a[x];
    x -= (x & (-x));
  }
  return res;
}
int main() {
  int i, j, m, size, ans, u;
  while (scanf("%d", &n) != EOF) {
    ans = 0;
    for (i = 0; i < n; i++) e[i].clear();
    for (i = 0; i < n; i++) {
      scanf("%d", &m);
      while (m--) {
        scanf("%d", &u);
        e[i].push_back(u);
      }
    }
    for (i = 0; i < n; i++) {
      memset(s, 0, sizeof(s));
      for (j = 0, k[0] = (i - 1 + n) % n, size = e[k[0]].size(); j < size; j++)
        M(s[0], e[k[0]][j]);
      for (j = 0, k[1] = (i + 1) % n, size = e[k[1]].size(); j < size; j++)
        M(s[1], e[k[1]][j]);
      sort(e[i].begin(), e[i].end());
      for (j = 1, size = e[i].size(); j < size; j++) {
        t[0] = S(s[0], e[i][j]) - S(s[0], e[i][j - 1]);
        t[1] = S(s[1], e[i][j]) - S(s[1], e[i][j - 1]);
        if (t[0] != t[1]) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
