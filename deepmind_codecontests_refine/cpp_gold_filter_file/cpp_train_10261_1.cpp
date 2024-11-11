#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010, inf = 1e9;
int n, m, x, ans;
int cnt[42], f[42], K[maxn];
vector<int> v1[maxn], v2[maxn];
inline void read(int &k) {
  int f = 1;
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
  k *= f;
}
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline bool check(int k, int b) {
  for (int i = 1; i <= 40; i++)
    if (cnt[i] && abs(b - f[i]) % gcd(k, i)) return 0;
  cnt[k]++;
  f[k] = b;
  return 1;
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) {
    read(K[i]);
    for (int j = 1; j <= K[i]; j++)
      read(x), v1[x].push_back(i), v2[x].push_back(j);
  }
  for (int i = 1; i <= m; i++) {
    ans = 0;
    memset(f, 0, sizeof(f));
    memset(cnt, 0, sizeof(cnt));
    for (int l = 0, r = 0; r < v1[i].size(); l++) {
      r = max(l, r);
      while (r < v1[i].size() && v1[i][r] - v1[i][l] == r - l &&
             check(K[v1[i][r]], v2[i][r]))
        r++;
      ans = max(ans, r - l);
      cnt[K[v1[i][l]]]--;
    }
    printf("%d\n", ans);
  }
}
