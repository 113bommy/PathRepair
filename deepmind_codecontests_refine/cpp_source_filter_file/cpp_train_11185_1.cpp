#include <bits/stdc++.h>
using namespace std;
int nextInt() {
  int x = 0, p = 1;
  char c;
  do {
    c = getchar();
  } while (c <= 32);
  if (c == '-') {
    p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * p;
}
const int maxn = 1024;
int n, m, q;
int a[maxn][maxn];
struct my {
  int n, m;
  int cols[maxn][maxn / 32 + 5];
  int a[maxn + 5][maxn + 5];
  int tmp[maxn + 5];
  int rr[maxn + 5], ll[maxn + 5];
  my() {}
  void xorVal(int x, int y) {
    if (a[x][y]) {
      a[x][y] = 0;
      cols[x][y / 32]--;
    } else {
      a[x][y] = 1;
      cols[x][y / 32]++;
    }
  }
  int fndMaxDown(int x, int y) {
    int l = x, r = n;
    int rr = (l / 32 + 1) * 32 - 1;
    for (int i = l; i <= rr; i++)
      if (!a[i][y]) return i - 1;
    int bl = l / 32 + 1, bl2 = r / 32;
    for (int i = bl; i <= bl2; i++)
      if (cols[y][i] != 32) {
        int lll = i * 32, rrr = i * 32 + 31;
        for (int j = lll; j <= rrr; j++)
          if (!a[j][y]) return j - 1;
        return rrr;
      }
    return n;
  }
  int query(int x, int y) {
    int l = 1, r = m;
    for (int i = y; i >= 1; i--)
      if (!a[x][i]) {
        l = i + 1;
        break;
      }
    for (int j = y; j <= m; j++) {
      if (!a[x][j]) {
        r = j - 1;
        break;
      }
    }
    for (int i = l; i <= r; i++) tmp[i] = fndMaxDown(x, i);
    for (int i = 0; i <= n; i++) rr[i] = l - 1, ll[i] = r + 1;
    for (int i = l; i <= y; i++) rr[tmp[i]] = i;
    for (int i = r; i >= y; i--) ll[tmp[i]] = i;
    for (int i = 1; i <= n; i++) {
      rr[i] = max(rr[i - 1], rr[i]);
      ll[i] = min(ll[i - 1], ll[i]);
    }
    int ans = 0;
    for (int z = x; z <= tmp[y]; z++) {
      ans = max(ans, (ll[z - 1] - rr[z - 1] - 1) * (z - x + 1));
    }
    return ans;
  }
};
my t1, t2, t3, t4;
int main() {
  memset(&t1, 0, sizeof(t1));
  memset(&t2, 0, sizeof(t2));
  memset(&t3, 0, sizeof(t3));
  memset(&t4, 0, sizeof(t4));
  n = nextInt();
  m = nextInt();
  q = nextInt();
  t1.n = n;
  t1.m = m;
  t2.m = n;
  t2.n = m;
  t3.n = n;
  t3.m = m;
  t4.m = n;
  t4.n = m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = nextInt();
      if (a[i][j]) {
        t1.xorVal(i, j);
        t2.xorVal(j, i);
        t3.xorVal(n - i + 1, j);
        t4.xorVal(m - j + 1, i);
      }
    }
  }
  for (int qq = 1; qq <= q; qq++) {
    int op = nextInt();
    if (op == 1) {
      int i, j;
      i = nextInt();
      j = nextInt();
      t1.xorVal(i, j);
      t2.xorVal(j, i);
      t3.xorVal(n - i + 1, j);
      t4.xorVal(m - j + 1, i);
    } else {
      int i, j;
      i = nextInt();
      j = nextInt();
      int z = t1.query(i, j);
      z = max(z, t2.query(j, i));
      z = max(z, t3.query(n - i + 1, j));
      z = max(z, t4.query(m - j + 1, i));
      printf("%d\n", z);
    }
  }
}
