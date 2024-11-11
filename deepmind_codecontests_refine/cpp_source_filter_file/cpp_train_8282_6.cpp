#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int MOD = (int)1e9 + 7, BAS = 233;
inline int sign(double x) { return x < -eps ? -1 : x > eps; }
inline int clz(int x) { return __builtin_clz(x); }
inline int clz(long long x) { return __builtin_clzll(x); }
inline int lg2(int x) { return !x ? -1 : 31 - clz(x); }
inline int lg2(long long x) { return !x ? -1 : 63 - clz(x); }
int AP(char *s) {
  unsigned hash = 0;
  for (int i = 0; s[i]; i++) {
    if (i & 1)
      hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
    else
      hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
  }
  return hash & 0x7FFFFFFF;
}
const int M = 55;
char s[M][M];
int n, m;
int a[3];
char t[3] = {'&', '0', 'a'};
int minn[3];
int tmp[3];
int rm[128];
void update(int &minn, char *s, char ch) {
  for (int i = 0; i < m; i++) {
    if (s[i] == ch) {
      minn = min(minn, min(i, m - i));
    }
  }
}
int main() {
  rm['&'] = 0;
  rm['0'] = 1;
  rm['a'] = 2;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s + i);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#' || s[i][j] == '*' || s[i][j] == '&')
        s[i][j] = '&';
      else if (s[i][j] >= '0' && s[i][j] <= '9')
        s[i][j] = '0';
      else
        s[i][j] = 'a';
    }
  int ans = 1000;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int z = j + 1; z < n; z++) {
        for (int f = 0; f < 3; f++) {
          a[f] = f;
          minn[f] = 1000;
        }
        for (int f = 0; f < n; f++)
          if (f != i && f != j && f != z) {
            minn[s[f][0] == '&' ? 0 : s[f][0] == '0' ? 1 : 2] = 0;
          }
        for (int f = 0; f < 3; f++) tmp[i] = minn[i];
        do {
          update(minn[rm[t[a[0]]]], s[i], t[a[0]]);
          update(minn[rm[t[a[1]]]], s[j], t[a[1]]);
          update(minn[rm[t[a[2]]]], s[z], t[a[2]]);
          ans = min(ans, minn[0] + minn[1] + minn[2]);
          for (int f = 0; f < 3; f++) minn[i] = tmp[i];
        } while (next_permutation(a, a + 3));
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
