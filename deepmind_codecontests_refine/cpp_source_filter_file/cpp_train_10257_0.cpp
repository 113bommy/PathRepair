#include <bits/stdc++.h>
using namespace std;
int n, m, tl[3010][3010], tz[3010][3010], tr[3010][3010], z[3010][3010],
    t[3010];
long long r, bit[3010];
vector<int> del[3010];
char c;
long long getsum(int index) {
  long long sum = 0;
  while (index) {
    sum += bit[index];
    index -= index & (-index);
  }
  return sum;
}
void update(int index, long long val) {
  while (index <= n) {
    bit[index] += val;
    index += index & (-index);
  }
  return;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf(" %c", &c);
      if (c == 'z') tl[i][j] = 1 + tl[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j > 0; j--) {
      if (tl[i][j]) {
        tr[i][j] = 1 + tr[i][j + 1];
        tz[i][j] = 1 + tz[i - 1][j + 1];
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= i; j++) {
      del[j].clear();
      t[j] = 0;
      bit[j] = 0;
    }
    for (int j = 1; i - j >= 0 && j <= n; j++) {
      update(j, 1);
      del[j + tl[j][i - j + 1]].push_back(j);
      t[j + tl[j][i - j + 1]]++;
      for (int k = 0; k < t[j]; k++) update(del[j][k], -1);
      r += getsum(j);
      r -= getsum(j - min(tr[j][i - j + 1], tz[j][i - j + 1]));
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      del[j].clear();
      t[j] = 0;
      bit[j] = 0;
    }
    for (int j = 1; i + j - 1 <= n && j <= m; j++) {
      update(j, 1);
      del[j + tl[i + j - 1][m - j + 1]].push_back(j);
      t[j + tl[i + j - 1][m - j + 1]]++;
      for (int k = 0; k < t[j]; k++) update(del[j][k], -1);
      r += getsum(j);
      r -= getsum(j - min(tr[i + j - 1][m - j + 1], tz[i + j - 1][m - j + 1]));
    }
  }
  printf("%d\n", r);
  return 0;
}
