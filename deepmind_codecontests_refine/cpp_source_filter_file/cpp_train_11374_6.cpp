#include <bits/stdc++.h>
using namespace std;
int num;
int n, m;
int T;
int cnt[2];
vector<vector<bool> > M;
int BalLayer(int layer);
int main(int argc, const char* argv[]) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    M.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      M[i].resize(m + 1);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", &num);
        M[i][j] = num;
      }
    }
    int ans = 0;
    for (int i = 1; i <= (m + n - 1) / 2; i++) {
      ans += BalLayer(i);
    }
    printf("%d\n", ans);
  }
  return 0;
}
int BalLayer(int layer) {
  int x1, y1, x2, y2;
  if (layer > m) {
    x1 = layer - m;
    y1 = m;
  } else {
    x1 = 1;
    y1 = layer;
  }
  if (layer > n) {
    y2 = m - (layer - n);
    x2 = 1;
  } else {
    y2 = m;
    x2 = n - layer + 1;
  }
  cnt[0] = 0;
  cnt[1] = 0;
  for (int x = x1, y = y1; x <= n && y >= 1; x++, y--) {
    cnt[M[x][y]]++;
  }
  for (int x = x2, y = y2; x <= n && y >= 1; x++, y--) {
    cnt[M[x][y]]++;
  }
  return min(cnt[0], cnt[1]);
}
