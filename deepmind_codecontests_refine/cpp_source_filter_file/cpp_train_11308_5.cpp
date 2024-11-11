#include <bits/stdc++.h>
using namespace std;
int Query(int i, int j) {
  printf("? %d %d\n", i, j);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  return k;
}
const int maxn = 10000;
int n, p[maxn], b[maxn];
int ans[maxn][2];
int cnt, tmp[maxn], inv[maxn];
int out[maxn];
int cnttmp[maxn], cntinv[maxn];
int main(void) {
  scanf("%d", &n);
  ans[0][0] = Query(0, 0);
  for (int i = 1; i < n; ++i) {
    ans[i][0] = Query(0, i);
    ans[i][1] = Query(i, 0);
  }
  for (tmp[0] = 0; tmp[0] < n; ++tmp[0]) {
    memset(cnttmp, 0, sizeof cnttmp);
    memset(cntinv, 0, sizeof cntinv);
    inv[0] = tmp[0] ^ ans[0][0];
    if (inv[0] >= n) {
      continue;
    }
    ++cnttmp[tmp[0]];
    ++cntinv[inv[0]];
    bool good = true;
    for (int i = 1; i < n; ++i) {
      tmp[i] = inv[0] ^ ans[i][1];
      inv[i] = tmp[0] ^ ans[i][0];
      if (tmp[i] >= n || inv[i] >= n) {
        good = false;
        break;
      }
      if (cnttmp[tmp[i]] || cntinv[inv[i]]) {
        good = false;
        break;
      }
      ++cnttmp[tmp[i]];
      ++cnttmp[inv[i]];
    }
    if (!good) {
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (tmp[inv[i]] != i) {
        good = false;
        break;
      }
    }
    if (good) {
      ++cnt;
      memcpy(out, tmp, sizeof out);
    }
  }
  printf("!\n%d\n", cnt);
  for (int i = 0; i < n; ++i) {
    printf("%d ", out[i]);
  }
  putchar('\n');
  return 0;
}
