#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
int n, len;
char Time[1000];
int dp[205][51][51][2];
int dx[] = {0, -1, 1};
int call(int t, int st, int cn, int dir) {
  if (t == len - 1) return inf;
  if (st == cn) {
    return t;
  }
  int &ret = dp[t][st][cn][dir];
  if (ret != -1) return ret;
  ret = t;
  int prev = st;
  if (dir == 1) {
    st++;
    if (st == n + 1) st = n - 1, dir = 0;
  } else {
    st--;
    if (!st) st = 2, dir = 1;
  }
  if (Time[t] == '0') {
    for (int k = 0; k < 3; k++) {
      int c1n = cn + dx[k];
      if (c1n >= 1 && c1n <= n && c1n != prev && c1n != st)
        ret = max(ret, call(t + 1, st, c1n, dir));
    }
  } else {
    for (int k = 1; k <= n; k++) {
      if (k != st) ret = max(ret, call(t + 1, st, k, dir));
    }
  }
  return ret;
}
int main() {
  double cl = clock();
  int m, k;
  scanf("%d %d %d", &n, &m, &k);
  char a[10], b[10];
  scanf("%s %s", a, b);
  scanf("%s", Time);
  len = strlen(Time);
  memset(dp, -1, sizeof(dp));
  int res = call(0, k, m, b[0] == 't');
  if (res >= inf)
    printf("Stowaway\n");
  else
    printf("Controller %d\n", res + 1);
  cl = clock() - cl;
  fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);
  return 0;
}
