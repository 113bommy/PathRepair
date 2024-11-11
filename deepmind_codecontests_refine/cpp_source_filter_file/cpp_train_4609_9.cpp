#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
const int maxn = 1000009;
const int base = 23;
long long pw[maxn];
int n;
string s[maxn];
vector<long long> h[maxn];
vector<int> p[maxn];
vector<long long> f[maxn];
int q[maxn];
int nex[maxn];
long long gethash(int i, int x, int a) {
  if (x < a) return h[i][x];
  ++x;
  long long L = (a ? h[i][a - 1] : 0) * pw[x - a] % P;
  long long R = h[i][x] - h[i][a] * pw[x - a] % P + P;
  return (L + R) % P;
}
int cmp(int i, int a, int j, int b) {
  int len1 = s[i].length() - (a != s[i].length());
  int len2 = s[j].length() - (b != s[j].length());
  int t = -1;
  for (int k = 19; k >= 0; --k) {
    if (t + (1 << k) >= min(len1, len2)) continue;
    int r = t + (1 << k);
    if (gethash(i, r, a) != gethash(j, r, b)) continue;
    t += 1 << k;
  }
  len1 = s[i].length();
  len2 = s[j].length();
  int l = t + 1, r = t + 1;
  if (a <= l) ++l;
  if (b <= r) ++r;
  l = (l >= len1) ? 0 : s[i][l];
  r = (r >= len2) ? 0 : s[j][r];
  if (l < r) return -1;
  if (l == r) return 0;
  if (l > r) return 1;
}
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 1000000; ++i) pw[i] = pw[i - 1] * base % P;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    int len = s[i].length();
    long long pre = 0;
    for (int j = 0; j < len; ++j) {
      pre = (pre * base + s[i][j]) % P;
      h[i].push_back(pre);
    }
    int l = 1, r = len + 1;
    nex[len - 1] = 0;
    for (int j = len - 2; j >= 0; --j) {
      if (s[i][j] == s[i][j + 1])
        nex[j] = nex[j + 1];
      else
        nex[j] = s[i][j + 1];
    }
    for (int j = 0; j <= len - 1; ++j) {
      if (s[i][j] > nex[j])
        q[l++] = j;
      else
        q[r--] = j;
    }
    q[l] = len;
    for (int j = 1; j <= len + 1; ++j) p[i].push_back(q[j]);
  }
  for (int i = 0; i < p[1].size(); ++i) f[1].push_back(1);
  for (int i = 2; i <= n; ++i) {
    long long pre = 0, t = 0;
    for (int j = 0; j < p[i].size(); ++j) {
      while (t < p[i - 1].size() && cmp(i - 1, p[i - 1][t], i, p[i][j]) <= 0)
        pre = (pre + f[i - 1][t++]) % P;
      f[i].push_back(pre);
    }
  }
  long long ans = 0;
  for (int j = 0; j < p[n].size(); ++j) ans = (ans + f[n][j]) % P;
  printf("%lld\n", ans);
  return 0;
}
