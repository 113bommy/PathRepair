#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);
template <class T, class S>
inline void add(T& a, S b) {
  a += b;
  if (a >= mod) a -= mod;
}
template <class T, class S>
inline void sub(T& a, S b) {
  a -= b;
  if (a < 0) a += mod;
}
template <class T, class S>
inline bool chkmax(T& a, S b) {
  return a < b ? a = b, true : false;
}
template <class T, class S>
inline bool chkmin(T& a, S b) {
  return a > b ? a = b, true : false;
}
int n, m, mask[N], c[N], cnt[N];
char s[N], t[N], ans[N];
bool check() {
  int sum = 0, ret = inf;
  for (int i = 0; i < 6; i++) sum += c[i];
  for (int s1 = 0; s1 < 64; s1++) {
    int tmp = 0;
    for (int i = 0; i < 6; i++)
      if (s1 >> i & 1) tmp += c[i];
    for (int s2 = 0; s2 < 64; s2++)
      if (s1 != s2) tmp += cnt[s2];
    chkmin(ret, tmp);
  }
  return sum == ret;
}
inline int getId(char c) { return c - 'a'; }
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) c[getId(s[i])]++;
  scanf("%d", &m);
  while (m--) {
    int p;
    scanf("%d%s", &p, t + 1);
    for (int i = 1; t[i]; i++) mask[p] |= 1 << getId(t[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!mask[i]) mask[i] = 63;
    cnt[mask[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    bool flag = false;
    for (int j = 0; j < 6; j++) {
      if (c[j] && mask[i] >> j & 1) {
        c[j]--;
        cnt[mask[i]]--;
        flag = check();
        if (flag) {
          ans[i] = 'a' + j;
          break;
        }
        c[j]++;
        cnt[mask[i]]++;
      }
    }
    if (!flag) return puts("Impossible"), 0;
  }
  ans[n + 1] = '\0';
  puts(ans + 1);
  return 0;
}
