#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int MX = 123456;
const int mod = (int)1e9 + 7;
const int base = 1023456789;
const unsigned long long BS1 = 10000019ULL;
const int INF = (1 << 29);
template <class T>
inline void fastScan(T &x) {
  register char c = getchar();
  int neg = 0;
  x = 0;
  for (; (c < 48 || c > 57) && (c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
int n, m, q;
int W[15];
int kunt[(1 << 12) + 10];
char str[15];
long long dp[(1 << 12) + 5][101];
bool Check(int nn, int pos) { return (bool)(nn & (1 << pos)); }
int P(int a, int b) {
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (Check(a, i) == Check(b, i)) {
      x += W[i];
    }
  }
  return x;
}
int main() {
  fastScan(n);
  fastScan(m);
  fastScan(q);
  for (int i = 0; i < n; i++) {
    fastScan(W[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", str);
    int x = 0;
    for (int j = 0; str[j]; j++) {
      if (str[j] == '1') {
        x += (1 << j);
      }
    }
    kunt[x]++;
  }
  for (int i = 0; i <= (1 << 12); i++) {
    int x = 0;
    for (int j = 0; j <= (1 << j); j++) {
      if (kunt[j] >= 0) {
        x = P(i, j);
        if (x <= 100) dp[i][x] += kunt[j];
      }
    }
  }
  for (int i = 0; i <= (1 << 12); i++) {
    for (int k = 1; k <= 100; k++) dp[i][k] += dp[i][k - 1];
  }
  for (int i = 0; i < q; i++) {
    int x = 0, k = 0;
    scanf("%s %d", str, &k);
    for (int j = 0; j < n; j++) {
      if (str[j] == '1') x += (1 << j);
    }
    printf("%d\n", dp[x][k]);
  }
}
