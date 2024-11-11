#include <bits/stdc++.h>
using namespace std;
int to[4100];
int p[4100][4100];
int pre[4100][110];
int w[110];
map<int, int> run;
int powi[20] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
int main() {
  int n, q, m;
  while (~scanf("%d%d%d", &n, &m, &q)) {
    run.clear();
    memset(w, 0, sizeof(w));
    memset(to, 0, sizeof(to));
    memset(p, 0, sizeof(p));
    memset(pre, 0, sizeof(pre));
    for (int i = n - 1; i >= 0; i--) scanf("%d", &w[i]);
    for (int i = 0; i <= powi[n] - 1; i++) {
      int k = i;
      for (int j = 11; j >= 0; j--) {
        if (k >= powi[j]) to[i] += w[j], k -= powi[j];
      }
    }
    for (int i = 0; i <= powi[n] - 1; i++)
      for (int j = 0; j <= powi[n] - 1; j++) {
        int tem = i ^ j ^ (powi[n] - 1);
        p[i][j] = to[tem];
      }
    for (int i = 1; i <= m; i++) {
      char s[20];
      scanf("%s", s);
      int sum = 0;
      for (int i = 0; i <= n - 1; i++)
        if (s[i] == '1') sum += powi[n - i - 1];
      run[sum]++;
    }
    for (int i = 0; i <= powi[n] - 1; i++)
      for (int j = 0; j <= powi[n] - 1; j++) {
        if (p[i][j] > 100) continue;
        pre[j][p[i][j]] += run[i];
      }
    for (int i = 0; i <= powi[n] - 1; i++)
      for (int j = 0; j <= 100; j++) pre[i][j] += pre[i][j - 1];
    for (int i = 1; i <= q; i++) {
      char s[20];
      int k;
      scanf("%s", s);
      int sum = 0;
      for (int i = 0; i <= n - 1; i++)
        if (s[i] == '1') sum += powi[n - i - 1];
      scanf("%d", &k);
      printf("%d\n", pre[sum][k]);
    }
  }
  return 0;
}
