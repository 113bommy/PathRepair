#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
}
void et() {
  puts("-1");
  exit(0);
}
int f[100005], w[100005];
int pa[100005][30], mi[100005][30];
long long ss[100005][30];
void fmain() {
  scanf("%d%lld", &n, &lk);
  for (int(i) = 0; (i) < (int)(n); (i)++) scanf("%d", f + i);
  for (int(i) = 0; (i) < (int)(n); (i)++) scanf("%d", w + i);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    pa[i][0] = f[i];
    mi[i][0] = w[i];
    ss[i][0] = w[i];
  }
  for (int j = 1; j < 30; j++)
    for (int i = 0; i < n; i++) {
      pa[i][j] = pa[pa[i][j - 1]][j - 1];
      mi[i][j] = min(mi[i][j - 1], mi[pa[i][j - 1]][j - 1]);
      ss[i][j] = ss[i][j - 1] + ss[pa[i][j - 1]][j - 1];
    }
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    int a = (1 << 30);
    long long b = 0, x = lk;
    int pos = i;
    for (int j = 29; j >= 0; j--) {
      if ((1LL << j) <= x) {
        x -= 1LL << j;
        a = min(a, mi[pos][j]);
        b += ss[pos][j];
        pos = pa[pos][j];
      }
    }
    printf("%lld %d\n", b, a);
  }
}
int main() {
  fmain();
  return 0;
}
