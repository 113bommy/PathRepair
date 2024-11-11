#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MOD = 1000000007;
int N = 100000;
long long Q[MAXN];
vector<pair<int, int> > query[MAXN];
long long p26[MAXN], p25[MAXN], c[MAXN], com[MAXN], cominv[MAXN], inv[MAXN];
void calcCom() {
  inv[0] = 0;
  inv[1] = 1;
  for (int i = 2; i <= N; ++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
  com[0] = cominv[0] = 1;
  for (int i = 1; i <= N; ++i) {
    com[i] = com[i - 1] * i % MOD;
    cominv[i] = cominv[i - 1] * inv[i] % MOD;
  }
}
char s[MAXN];
map<int, long long> ansMap;
int main() {
  calcCom();
  p26[0] = p25[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    p26[i] = p26[i - 1] * 26 % MOD;
    p25[i] = p25[i - 1] * 25 % MOD;
  }
  int n, len;
  scanf("%d", &n);
  scanf("%s\n", s);
  len = strlen(s);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d ", &x);
    if (x == 2) {
      int t;
      scanf("%d\n", &t);
      Q[i] = t;
      query[len].push_back(make_pair(t, i));
    } else {
      Q[i] = -1;
      scanf("%s\n", s);
      len = strlen(s);
    }
  }
  for (int k = 1; k <= n; k++)
    if (!query[k].empty()) {
      sort(query[k].begin(), query[k].end());
      int mx = query[k].rbegin()->first;
      for (int i = 0; i <= mx; i++) {
        if (i == k)
          c[i] = 1;
        else if (i > k)
          c[i] = (c[i - 1] * i) % MOD * inv[i - k] % MOD;
      }
      long long ans = 0;
      int p = 0;
      while (query[k][p].first < k && p < query[k].size()) {
        Q[query[k][p].second] = 0;
        p++;
      }
      for (int j = k; j <= mx; j++) {
        if (j == k)
          ans = 1;
        else
          ans = ((ans - c[j - 1] * p25[j - k - 1]) % MOD * 26 +
                 c[j - 1] * p25[j - k - 1] % MOD + c[j] * p25[j - k] % MOD) %
                MOD;
        if (ans < 0) ans += MOD;
        while (query[k][p].first == j && p < query[k].size()) {
          Q[query[k][p].second] = ans;
          p++;
        }
      }
    }
  for (int i = 0; i < n; i++) {
    if (Q[i] >= 0) printf("%I64d\n", Q[i]);
  }
}
