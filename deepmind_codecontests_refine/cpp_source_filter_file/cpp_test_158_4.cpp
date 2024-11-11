#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 9;
const long long MOD = 1e9 + 7;
const int mod = 998244353;
inline long long qpow(long long b, long long e, long long m) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y, y = z - y * (a / b);
  return d;
}
int x[19];
char s[19][maxn];
int ans[maxn];
pair<int, int> val[maxn];
bool cmp(pair<int, int> A, pair<int, int> B) { return A.second < B.second; }
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    int v = 0;
    for (int i = 0; i < (1 << n); i++) {
      int res = 0;
      for (int j = 0; j < n; j++) {
        if (i >> j & 1)
          res += x[j];
        else
          res -= x[j];
      }
      for (int k = 0; k < m; k++) {
        val[k].first = 0;
        val[k].second = k;
      }
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
          if (s[j][k] == '1') {
            if (i >> j & 1)
              val[k].first--;
            else
              val[k].first++;
          }
        }
      }
      sort(val, val + m);
      for (int j = 0; j < m; j++) {
        res += (j + 1) * val[j].first;
      }
      if (res > v) {
        v = res;
        for (int j = 0; j < m; j++) {
          ans[val[j].second] = j + 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
}
