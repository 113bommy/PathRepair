#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
void qread(int &x) {
  int neg = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = 10 * x + c - '0', c = getchar();
  x *= neg;
}
const int maxn = 200005;
const int mod = 1e9 + 7;
string A, B;
int c[2][2], t[2][2];
int fac[maxn], inv[maxn];
char ch[maxn];
int quickpow(int x, int pow) {
  int res = 1;
  for (; pow; pow >>= 1) {
    if (pow & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
  }
  return res;
}
int C(int a, int b) {
  if (b < 0) return 1;
  return 1LL * fac[a] * inv[b] % mod * inv[a - b] % mod;
}
int calc(int beg, int t[2][2]) {
  if (!t[0][0] && !t[0][1] && !t[1][0] && !t[1][1]) return 1;
  if (!t[beg][0] && !t[beg][1]) return 0;
  if (!t[beg][beg ^ 1] && t[beg ^ 1][beg ^ 1]) return 0;
  if (t[0][0] && t[1][1] && (!t[0][1] && !t[1][0])) return 0;
  int diff = t[beg][beg ^ 1] - t[beg ^ 1][beg];
  if (diff < 0 || diff > 1) return 0;
  int g1 = 1 + t[beg ^ 1][beg], g2 = t[beg][beg ^ 1];
  return 1LL * C(t[beg][beg] + g1 - 1, g1 - 1) *
         C(t[beg ^ 1][beg ^ 1] + g2 - 1, g2 - 1) % mod;
}
int solve(string s, int t[2][2]) {
  if (s[0] == '0') s = s.substr(1);
  if (s == "") return 0;
  if (t[0][0] + t[0][1] + t[1][0] + t[1][1] < s.size() - 1) return calc(1, t);
  if (t[0][0] + t[0][1] + t[1][0] + t[1][1] >= s.size()) return 0;
  int ans = 0;
  for (int(i) = 0; (i) < s.size(); i++) {
    if (s[i] == '1' && i > 0 && t[s[i - 1] - '0'][0]) {
      t[s[i - 1] - '0'][0]--;
      ans = (ans + calc(0, t)) % mod;
      t[s[i - 1] - '0'][0]++;
    }
    if (i > 0) t[s[i - 1] - '0'][s[i] - '0']--;
    if (t[s[i - 1] - '0'][s[i] - '0'] < 0) break;
  }
  if (t[0][0] == 0 && t[0][1] == 0 && t[1][0] == 0 && t[1][1] == 0)
    ans = (ans + 1) % mod;
  return ans;
}
int main() {
  fac[0] = inv[0] = 1;
  for (int(i) = 1; (i) <= 200000; i++) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
    inv[i] = quickpow(fac[i], mod - 2);
  }
  scanf("%s", ch);
  A = ch;
  scanf("%s", ch);
  B = ch;
  for (int(i) = 0; (i) < 2; i++)
    for (int(j) = 0; (j) < 2; j++) scanf("%d", &c[i][j]), t[i][j] = c[i][j];
  A[A.size() - 1]--;
  for (int i = A.size() - 1; i >= 0; i--) {
    if (A[i] < '0') A[i] = '1', A[i - 1]--;
  }
  printf("%d\n", (solve(B, c) - solve(A, t) + mod) % mod);
  return 0;
}
