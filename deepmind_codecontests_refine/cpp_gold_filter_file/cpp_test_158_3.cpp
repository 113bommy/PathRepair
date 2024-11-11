#include <bits/stdc++.h>
using namespace std;
int n, m, a[10], c[10005];
char b[10][10005];
vector<int> g[10];
int id[10005];
bool cmp(int i1, int i2) { return c[i1] < c[i2]; }
int p[10005], p2[10005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("\n%s", b[i] + 1);
      g[i].clear();
      for (int j = 1; j <= m; j++) {
        if (b[i][j] == '1') {
          g[i].push_back(j);
        }
      }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) id[i] = i;
    for (int i = 0; i < (1 << n); i++) {
      memset(c, 0, sizeof(c));
      for (int j = 0; j < n; j++) {
        for (int k : g[j]) {
          if (i & (1 << j))
            c[k]++;
          else
            c[k]--;
        }
      }
      sort(id + 1, id + 1 + m, cmp);
      for (int j = 1; j <= m; j++) {
        p[id[j]] = j;
      }
      long long sum = 0;
      for (int j = 0; j < n; j++) {
        int h = 0;
        for (int k : g[j]) {
          h += p[k];
        }
        sum += abs(a[j] - h);
      }
      if (sum >= ans) {
        ans = sum;
        for (int j = 1; j <= m; j++) {
          p2[j] = p[j];
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      printf("%d ", p2[i]);
    }
    printf("\n");
  }
  return 0;
}
