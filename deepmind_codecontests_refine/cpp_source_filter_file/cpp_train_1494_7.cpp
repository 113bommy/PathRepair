#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int maxmax = 4 * N;
int n, m, x[2 * N], kk, i, j, z, res, dif[2 * N], all[N], h[N], r, l, tmp, k;
vector<int> start[N], last[N], cnt[N];
int main() {
  scanf("%d%d%d", &n, &m, &kk);
  for (i = 0; i < n; i++) scanf("%d", &x[i]);
  for (i = 0; i < n; i++)
    if (i > 0 && x[i] == x[i - 1]) {
      j = x[i];
      all[j]++;
      h[j]++;
      z = start[j].size() - 1;
      last[j][z] = i;
      cnt[j][z]++;
    } else {
      j = x[i];
      all[j]++;
      h[j]++;
      start[j].push_back(i);
      last[j].push_back(i);
      cnt[j].push_back(1);
    }
  sort(h + 1, h + m + 1);
  for (k = 1; k <= m; k++)
    if (all[k] > h[max(0, m - 100)]) {
      n = start[k].size();
      if (n == 0) continue;
      if (n == 1) {
        res = max(res, cnt[k][0]);
        continue;
      };
      for (j = 1; j < n; j++)
        dif[j] = dif[j - 1] + start[k][j] - last[k][j - 1] - 1;
      dif[n] = maxmax;
      tmp = cnt[k][0];
      r = 0;
      for (l = 0; l < n; l++) {
        while (r < (n - 1) && dif[r + 1] - dif[l] <= kk) {
          r++;
          tmp += cnt[k][r];
        }
        res = max(res, tmp);
        if (r == n - 1) break;
        tmp -= cnt[k][l];
      }
    }
  printf("%d\n", res);
}
