#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int maxBit = 20;
int n, m, t, a[N], p[N], ans[N], last[N], pre[N], anc[N][maxBit], pos[N],
    rez[N];
pair<int, int> q[N];
int prev(int i) {
  if (i == 1) {
    return n;
  }
  return i - 1;
}
void preprocess() {
  for (int i = 1; i <= m; i++) {
    last[a[i]] = i;
    pre[i] = last[p[prev(pos[a[i]])]];
  }
  for (int bit = 0; bit <= maxBit - 1; bit++) {
    for (int i = 1; i <= m; i++) {
      if (bit == 0) {
        anc[i][bit] = pre[i];
      } else {
        anc[i][bit] = anc[anc[i][bit - 1]][bit - 1];
      }
    }
  }
  int mxAns = -1;
  for (int i = m; i >= 1; i--) {
    int poz = i;
    for (int bit = maxBit - 1; bit >= 0; bit--) {
      if ((n - 1) & (1 << bit)) {
        poz = anc[poz][bit];
      }
    }
    mxAns = max(mxAns, poz);
    ans[i] = mxAns;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    pos[p[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  preprocess();
  for (int i = 1; i <= t; i++) {
    scanf("%d%d", &q[i].first, &q[i].second);
    if (ans[q[i].second] >= q[i].first) {
      rez[i] = 1;
    }
  }
  for (int i = 1; i <= t; i++) {
    printf("%d", rez[i]);
  }
  return 0;
}
