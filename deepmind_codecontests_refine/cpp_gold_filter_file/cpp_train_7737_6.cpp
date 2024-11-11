#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int n, m;
int a, b;
int h[1005][1005];
int d[1005][13];
long long mn[1005][1005], mn2[1005][1005];
long long sum[1005][1005], s[1005][1005];
long long w[1005][1005];
bool used[1005][1005];
pair<int, int> p[1005 * 1005];
pair<int, int> ans[1005 * 1005];
bool Cmp(pair<int, int> p1, pair<int, int> p2) {
  if (w[p1.first][p1.second] != w[p2.first][p2.second])
    return w[p1.first][p1.second] < w[p2.first][p2.second];
  return p1 < p2;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &a, &b);
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(m); j++) {
      scanf("%d", &h[i][j]);
    }
  }
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(m); j++) {
      d[j][0] = h[i][j];
    }
    for (int k = 1; k <= int(13 - 1); k++) {
      for (int j = 0; j < int(m); j++) {
        d[j][k] = d[j][k - 1];
        if (j + (1 << (k - 1)) < m) {
          d[j][k] = min(d[j][k], d[j + (1 << (k - 1))][k - 1]);
        }
      }
    }
    int t = 0;
    while ((1 << (t + 1)) < b) t++;
    for (int j = 0; j < int(m - b + 1); j++) {
      mn[i][j] = min(d[j][t], d[j + b - (1 << t)][t]);
    }
  }
  for (int j = 0; j < int(m - b + 1); j++) {
    for (int i = 0; i < int(n); i++) {
      d[i][0] = mn[i][j];
    }
    for (int k = 1; k <= int(13 - 1); k++) {
      for (int i = 0; i < int(n); i++) {
        d[i][k] = d[i][k - 1];
        if (i + (1 << (k - 1)) < n) {
          d[i][k] = min(d[i][k], d[i + (1 << (k - 1))][k - 1]);
        }
      }
    }
    int t = 0;
    while ((1 << (t + 1)) < a) t++;
    for (int i = 0; i < int(n - a + 1); i++) {
      mn2[i][j] = min(d[i][t], d[i + a - (1 << t)][t]);
    }
  }
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(m); j++) {
      s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] + h[i][j] - s[i][j];
    }
  }
  for (int i = 0; i < int(n - a + 1); i++) {
    for (int j = 0; j < int(m - b + 1); j++) {
      sum[i][j] = s[i + a][j + b] - s[i][j + b] - s[i + a][j] + s[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < int(n - a + 1); i++) {
    for (int j = 0; j < int(m - b + 1); j++) {
      w[i][j] = sum[i][j] - mn2[i][j] * a * b;
      p[cnt] = make_pair(i, j);
      cnt++;
    }
  }
  sort(p, p + cnt, Cmp);
  int sz = 0;
  for (int it = 0; it < int(cnt); it++) {
    int i = p[it].first;
    int j = p[it].second;
    if (used[i][j]) continue;
    ans[sz] = p[it];
    sz++;
    for (int x = max(i - a + 1, 0); x < i + a; x++) {
      for (int y = max(j - b + 1, 0); y < j + b; y++) {
        used[x][y] = true;
      }
    }
  }
  cout << sz << endl;
  for (int i = 0; i < int(sz); i++) {
    printf("%d %d %I64d\n", ans[i].first + 1, ans[i].second + 1,
           w[ans[i].first][ans[i].second]);
  }
  return 0;
}
