#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
using namespace std;
const int N = 200050;
const int MOD = 1000000007;
long long step, len, n, m, T = 1, k, lent1, lent2, con1, con2, a[N], ans[N],
                           p[N];
char tmp[N], t1[N], t2[N], t3[N], nex[N];
struct matrix {
  long long a[4][4];
  matrix() { memset(a, 0, sizeof a); }
  void init() { a[1][1] = a[2][2] = a[3][3] = 1; }
};
matrix operator*(matrix a, matrix b) {
  matrix c;
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
      for (int k = 1; k <= 3; k++)
        (c.a[i][j] += a.a[i][k] * b.a[k][j] % MOD) %= MOD;
  return c;
}
matrix Pow(matrix a, long long b) {
  matrix res;
  res.init();
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long KMP(int n, char *s, int m, char *t, int mid) {
  int l = max(1, mid - n + 2), r = min(m, mid + n - 1);
  if (mid == -1) l = 1, r = m;
  long long ret = 0;
  for (int i = l, j = 0; i <= r; i++) {
    while (j >= 0 && s[j + 1] != t[i]) j = p[j];
    j++;
    if (j == n) {
      ret++;
      j = p[j];
    }
  }
  return ret;
}
pair<long long, long long> getn(char *s, int n, char *t, int m, int mark) {
  pair<long long, long long> now = pair<long long, long long>(0, 0);
  int cnt = 0, mid = 0;
  for (int i = 1; i <= n; i++) nex[++cnt] = s[i];
  mid = cnt;
  for (int i = 1; i <= m; i++) nex[++cnt] = t[i];
  now.first = KMP(len, tmp, cnt, nex, mid);
  cnt = 0;
  for (int i = 1; i <= m; i++) nex[++cnt] = t[i];
  mid = cnt;
  for (int i = 1; i <= n; i++) nex[++cnt] = s[i];
  now.second = KMP(len, tmp, cnt, nex, mid);
  ans[mark] = KMP(len, tmp, m, t, -1);
  return now;
}
void change() {
  for (register int i = 1; i <= lent2; i++) t3[i] = t2[i];
  for (register int i = 1; i <= lent1; i++) t3[i + lent2] = t1[i];
  for (register int i = 1; i <= lent2; i++) t1[i] = t2[i];
  for (register int i = 1; i <= lent1 + lent2; i++) t2[i] = t3[i];
  int ll = lent1;
  lent1 = lent2;
  lent2 = ll + lent2;
}
void init() {
  t1[1] = 'a', t2[1] = 'b';
  lent1 = lent2 = step = 1;
  ans[1] = KMP(len, tmp, 1, t1, -1);
  ans[2] = KMP(len, tmp, 1, t2, -1);
  for (int i = 3; i; i++) {
    step = i - 1;
    change();
    pair<long long, long long> now = getn(t1, lent1, t2, lent2, i);
    con1 = now.first, con2 = now.second;
    if (lent1 >= len && lent2 >= len) break;
  }
}
void getp(int n, char *tmp) {
  p[0] = -1;
  for (register int i = 1, j = -1; i <= n; i++) {
    while (j >= 0 && tmp[j + 1] != tmp[i]) j = p[j];
    p[i] = ++j;
  }
}
long long solve() {
  matrix A, B;
  A.a[1][1] = A.a[1][2] = A.a[2][1] = A.a[3][3] = 1;
  A.a[3][1] = con2;
  B.a[1][1] = B.a[1][2] = B.a[2][1] = B.a[3][3] = 1;
  B.a[3][1] = con1;
  matrix C = A * B;
  long long Tim = (k - (step + 1));
  C = Pow(C, Tim >> 1);
  if ((Tim >> 1) * 2LL != Tim) C = C * A;
  return (long long)(ans[step + 1] * C.a[1][1] % MOD + ans[step] * C.a[2][1] +
                     C.a[3][1]) %
         MOD;
}
signed main() {
  scanf("%lld%lld", &k, &m);
  for (; T <= m; T++) {
    scanf("%s", tmp + 1);
    len = strlen(tmp + 1);
    getp(len, tmp);
    init();
    if (k <= step + 1) {
      printf("%lld\n", ans[k]);
      continue;
    }
    printf("%lld\n", (solve() % MOD + MOD) % MOD);
  }
  return 0;
}
