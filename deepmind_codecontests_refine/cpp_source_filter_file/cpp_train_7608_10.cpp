#include <bits/stdc++.h>
using namespace std;
char t[12 + 1];
int n, m, q;
int vals[1 << 12], w[12], w2[12];
pair<int, int> ans[1 << 12][1 << 12];
int parse() {
  int v = 0;
  for (int j = int(0); j < int(n); j++) v += (t[j] - '0') << n - j - 1;
  return v;
}
int main() {
  while (scanf("%d %d %d", &n, &m, &q) != EOF) {
    for (int i = int(0); i < int(n); i++) {
      scanf("%d", w + i);
    }
    for (int i = int(0); i < int(1 << n); i++) vals[i] = 0;
    for (int i = int(0); i < int(m); i++) {
      scanf("%s", t);
      vals[parse()]++;
    }
    for (int i = int(0); i < int(1 << n); i++) {
      w2[i] = 0;
      for (int j = int(0); j < int(n); j++)
        if (i & 1 << j) w2[i] += w[n - j - 1];
    }
    for (int i = int(0); i < int(1 << n); i++) {
      for (int j = int(0); j < int(1 << n); j++) {
        ans[i][j] = pair<int, int>(w2[~(i ^ j) & (1 << n) - 1], vals[j]);
      }
      sort(ans[i], ans[i] + (1 << n));
      for (int j = int(1); j < int(1 << n); j++)
        ans[i][j].second += ans[i][j - 1].second;
    }
    for (int i = int(0); i < int(q); i++) {
      int k;
      scanf("%s %d", t, &k);
      int v = parse();
      int p = upper_bound(ans[v], ans[v] + (1 << n),
                          pair<int, int>(k, 1000000000)) -
              ans[v];
      int pr = 0;
      if (p) pr = ans[v][p - 1].second;
      printf("%d\n", pr);
    }
  }
  return 0;
}
