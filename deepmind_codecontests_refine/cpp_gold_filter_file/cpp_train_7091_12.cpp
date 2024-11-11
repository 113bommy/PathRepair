#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const long long int INFLL = 0x3f3f3f3f3f3f3f3fll;
long long int getint() {
  long long int ret = 0;
  bool f = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f ^= 1;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return f ? -ret : ret;
}
using namespace std;
const int MAXN = 26, MAXD = 123, mod = 12345;
int p[MAXN + 10], val[MAXN + 10], num[MAXN + 10], w;
vector<int> vec[MAXN + 10];
bool ok[MAXD + 10];
void decode(int w) {
  for (int i = 26; i >= 1; --i)
    if (p[i]) {
      num[i] = w / val[i];
      w %= val[i];
    }
}
int a[MAXD + 10][MAXD + 10], ret[MAXD + 10][MAXD + 10],
    tmp[MAXD + 10][MAXD + 10];
void multi(int a[MAXD + 10][MAXD + 10], int b[MAXD + 10][MAXD + 10]) {
  memset(tmp, 0, sizeof tmp);
  for (int i = 0; i < w; ++i)
    for (int k = 0; k < w; ++k)
      for (int j = 0; j < w; ++j)
        tmp[i][k] = (tmp[i][k] + a[i][j] * b[j][k]) % mod;
  memcpy(a, tmp, sizeof tmp);
}
int main() {
  long long int n = getint();
  int m = getint();
  if (!n) {
    printf("1\n");
    return 0;
  }
  if (!m) {
    printf("0\n");
    return 0;
  }
  char s[2];
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s);
    int t = getint();
    int a = *s - 'A' + 1;
    if (!p[a])
      p[a] = t;
    else
      p[a] *= t;
    vec[a].push_back(t);
  }
  w = 1;
  for (int i = 1; i <= 26; ++i)
    if (p[i]) {
      val[i] = w;
      w *= p[i];
    }
  for (int i = 0; i < w; ++i) {
    decode(i);
    ok[i] = 1;
    for (int j = 1; j <= 26; ++j)
      if (p[j]) {
        bool flag = 1;
        for (int k = 0; flag && k < vec[j].size(); ++k)
          if (num[j] % vec[j][k] == 0) flag = 0;
        if (flag) {
          ok[i] = 0;
          break;
        }
      }
    for (int j = 1; j <= 26; ++j)
      if (p[j]) {
        if (num[j] < p[j] - 1)
          a[i][i + val[j]]++;
        else
          a[i][i - (p[j] - 1) * val[j]]++;
      }
  }
  for (int i = 0; i < w; ++i) ret[i][i] = 1;
  for (; n; n >>= 1, multi(a, a))
    if (n & 1) multi(ret, a);
  int ans = 0;
  for (int i = 0; i < w; ++i)
    if (ok[i]) ans = (ans + ret[0][i]) % mod;
  printf("%d\n", ans);
  return 0;
}
