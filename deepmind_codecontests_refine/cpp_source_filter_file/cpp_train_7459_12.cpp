#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
inline unsigned int myrand(int n) {
  unsigned int u = rand() % n;
  int c = rand() % 10;
  u ^= u << c;
  u ^= (u << 7) & 263692864;
  u ^= (u << 15) & 402273075;
  u %= n;
  return u;
}
char s[1000011], t[1000011];
char st[1000011];
int up[1000011], bk[1000011];
void func(int n, int *z, char *t) {
  z[0] = 0;
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && t[i + z[i]] == t[z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}
int rgt[1000011], lft[1000011];
int pos[1000011];
int mx[1000011];
set<pair<int, int> > ss;
set<pair<int, int> >::iterator it;
int bit[1000011];
void update(int u, int v) {
  while (u) {
    smin(bit[u], v);
    u -= u & -u;
  }
}
int calc(int u) {
  int ans = 0x3f3f3f3f;
  while (u < 1000011) {
    smin(ans, bit[u]);
    u += u & -u;
  }
  return ans;
}
int main() {
  int n, m, k;
  memset(bit, 0x3f, sizeof bit);
  cin >> n >> m >> k;
  scanf("%s %s", s, t);
  strcpy(st, t);
  strcat(st, s);
  func(n + m, up, st);
  for (int i = 1; i <= n; i++) rgt[i] = min(up[i + m - 1], k);
  reverse(st, st + m);
  reverse(st + m, st + n + m);
  func(n + m, bk, st);
  for (int i = 1; i <= n; i++) lft[i] = min(k, bk[n + m - i]);
  for (int i = n - m + 1, j = n; i >= 1; i--, j--) {
    if (lft[j]) update(lft[j], j);
    if (rgt[i] >= m) {
      int ed = n, st;
      smin(ed, i + 2 * k - 1);
      st = ed - 2 * k + 1;
      puts("Yes");
      cout << st << ' ' << st + k << endl;
      continue;
    }
    int ps = calc(m - rgt[i]);
    if (ps == 0x3f3f3f3f) continue;
    if (min(rgt[i], n + m - ps - k) >= max(m - lft[ps], k - i + 1)) {
      puts("Yes");
      int tmp = min(rgt[i], n + m - ps - k);
      cout << i - (k - tmp) << ' ' << ps - (m - tmp) + 1 << endl;
      return 0;
    }
  }
  puts("No");
  return 0;
}
