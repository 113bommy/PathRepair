#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], c[N];
map<int, int> q1, q2;
int main() {
  int n, m, p;
  while (~scanf("%d%d%d", &n, &m, &p)) {
    memset(c, 0, sizeof(c));
    q1.clear();
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
      scanf("%d", &b[i]);
      q1[b[i]]++;
    }
    int cnt = q1.size(), len = 0;
    for (int i = 1; i < p; i++) {
      int l = i, r = i, sum = 0;
      q2.clear();
      while (r <= n) {
        q2[a[r]]++;
        if (q2[a[r]] == q1[a[r]]) sum++;
        if (q2[a[r]] > q1[a[r]]) {
          if (q2[a[l]] == q1[a[l]]) sum--;
          q2[a[l]]--;
          l += p;
          r += p;
          continue;
        }
        if (sum == cnt) {
          c[len++] = l;
          if (q2[a[l]] == q1[a[l]]) sum--;
          q2[a[l]]--;
          l += p;
          r += p;
          continue;
        }
        if ((1 + (r - l) / p) == m) {
          if (q2[a[l]] == q1[a[l]]) sum--;
          q2[a[l]]--;
          l += p;
          r += p;
          continue;
        }
        r += p;
        if (n - l + 1 < m) break;
      }
    }
    sort(c, c + len);
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
      if (i == 0)
        printf("%d", c[i]);
      else
        printf(" %d", c[i]);
    }
    printf("\n");
  }
}
