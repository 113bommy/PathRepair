#include <bits/stdc++.h>
using namespace std;
int z[1000100], y[1000100], add[1000100];
char s[1000100];
int n, m, N;
void prepare() {
  for (int i = 1, l = 0, r = -1; i < N; ++i) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < N && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}
int main() {
  scanf("%d%d\n", &n, &m);
  gets(s);
  N = strlen(s);
  for (int i = 0; i < m; ++i) {
    scanf("%d", y + i);
  }
  prepare();
  for (int i = 1; i < m; ++i) {
    int d = y[i] - y[i - 1];
    if (d + 1 <= N && d + z[d] < N) {
      printf("%d\n", 0);
      return 0;
    }
  }
  int ans = 1;
  int cur = 0, bal = 0;
  for (int i = 1; i <= n; ++i) {
    if (y[cur] == i) {
      add[i]++;
      add[i + N]--;
      ++cur;
    }
    bal += add[i];
    if (!bal) {
      ans = (ans * 26LL) % ((int)1e9 + 7);
    }
  }
  printf("%d", ans);
  return 0;
}
