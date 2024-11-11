#include <bits/stdc++.h>
using namespace std;
const int maxn = 402;
int n, m, ans;
int a[maxn][maxn];
short int lin[maxn][maxn][maxn];
int v[maxn * maxn];
short int f[maxn][maxn][maxn];
int du[maxn][maxn];
bool ju(int k, int i, int j) { return !(v[a[k][i]] || v[a[k][j]]); }
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = (1); (i) <= (n); (i)++)
    for (int(j) = (1); (j) <= (m); (j)++) scanf("%d", &a[i][j]);
  for (int(i) = (1); (i) <= (n); (i)++) {
    for (int(j) = (1); (j) <= (m); (j)++) {
      int tot = 0;
      for (int(k) = (i); (k) <= (n); (k)++) {
        if (v[a[k][j]]) break;
        v[a[k][j]] = 1;
        tot = k;
      }
      du[j][i] = tot;
      for (int(k) = (i); (k) <= (n); (k)++) v[a[k][j]] = 0;
    }
  }
  for (int(i) = (1); (i) <= (m); (i)++) {
    for (int(j) = (i + 1); (j) <= (m); (j)++) {
      int tail = 1;
      for (int(k) = (1); (k) <= (n); (k)++) {
        while (tail <= n && ju(tail, i, j) && a[tail][i] != a[tail][j]) {
          v[a[tail][i]]++;
          v[a[tail][j]]++;
          tail++;
        }
        lin[i][j][k] = tail - k;
        if (tail > k) {
          v[a[k][i]]--;
          v[a[k][j]]--;
        } else
          tail = k + 1;
      }
    }
  }
  for (int(i) = (0); (i) <= (m - 1); (i)++)
    for (int(j) = (1); (j) <= (m - i); (j)++) {
      for (int(k) = (1); (k) <= (n); (k)++) {
        if (i == 0)
          f[j][j][k] = du[j][k];
        else
          f[j][j + i][k] = min(min(f[j + 1][j + i][k], f[j][j + i - 1][k]),
                               lin[j][j + i][k]);
      }
    }
  ans = 0;
  for (int(i) = (1); (i) <= (m); (i)++)
    for (int(j) = (i); (j) <= (m); (j)++)
      for (int(k) = (1); (k) <= (n); (k)++)
        ans = max(ans, f[i][j][k] * (j - i + 1));
  printf("%d\n", ans);
  return 0;
}
