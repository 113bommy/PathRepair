#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, LEN = 100010, MAX = 2010;
inline void add(int &a, int b) { a = (((long long)a) + b) % MOD; }
char str[LEN];
int dpL[MAX][MAX], dpR[MAX][2 * MAX], diff, total, m, n;
int g(int i, int j) {
  ;
  if (j + total < 0) return 0;
  if (i == m - n) return j + total == 0;
  int &ret = dpR[i][j + MAX];
  if (ret == -1) {
    ret = 0;
    add(ret, g(i + 1, j + 1));
    add(ret, g(i + 1, j - 1));
  }
  return ret;
}
int f(int i, int j) {
  ;
  if (j < 0) return 0;
  if (i == m - n) return j + diff >= 0 && j + total == 0;
  int &ret = dpL[i][j];
  if (ret == -1) {
    ret = 0;
    add(ret, f(i + 1, j + 1));
    add(ret, f(i + 1, j - 1));
    if (j + diff >= 0) add(ret, g(i, j));
  }
  return ret;
}
int main() {
  memset(dpL, -1, sizeof dpL);
  memset(dpR, -1, sizeof dpR);
  scanf("%d %d %s", &m, &n, str);
  diff = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(')
      cnt++;
    else
      cnt--;
    ;
    diff = min(diff, cnt);
  }
  total = cnt;
  ;
  printf("%d\n", f(0, 0));
  return 0;
}
