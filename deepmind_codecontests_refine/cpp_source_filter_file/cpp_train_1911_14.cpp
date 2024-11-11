#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int a[250035 * 2], f[250035 * 2][20], w[250035 * 2], p[250035 * 2][20];
int mi(int x, int y) { return w[x] < w[y] ? x : y; }
void stBuild() {
  for (int j = 1; j <= 20; j++)
    for (int i = 0; i + (1 << j) - 1 < n + n; i++) {
      f[i][j] = mi(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
}
int stQuery(int i, int j) {
  if (i < 0) return 0;
  int k = (int)(log((double)(j - i + 1)) / log(2.0));
  return mi(f[i][k], f[j - (1 << k) + 1][k]);
}
int main() {
  scanf("%d", &n);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    scanf("%d", a + i);
    a[i + n] = a[i];
  }
  for (int(i) = 0; (i) < (int)(n + n); (i)++) {
    w[i] = i - a[i];
    f[i][0] = i;
  }
  stBuild();
  for (int(i) = 0; (i) < (int)(n + n); (i)++) p[i][0] = stQuery(w[i], i);
  for (int j = 1; j <= 20; j++)
    for (int i = 0; i < n + n; i++) p[i][j] = p[p[i][j - 1]][j - 1];
  long long ans = 0;
  for (int i = n; i < n + n; i++) {
    int ss = i - n + 1;
    ans++;
    if (w[i] <= ss) continue;
    ans++;
    for (int j = 20, x = i; j >= 0; j--) {
      if (w[p[x][j]] > ss) {
        x = p[x][j];
        ans += 1 << j;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
