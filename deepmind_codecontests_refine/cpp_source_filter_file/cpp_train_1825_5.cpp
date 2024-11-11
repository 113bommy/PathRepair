#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long fh = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= fh;
}
template <typename T>
void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writeln(T x) {
  write(x);
  puts("");
}
long long nn, mm, n, m;
long long lt[200005];
char ct[200005];
long long ls[200005];
char cs[200005];
long long ne[200005];
signed main() {
  cin >> nn >> mm;
  char tar = '?';
  long long cur = 0;
  for (long long i = 1; i <= nn; ++i) {
    long long l;
    char c;
    cin >> l;
    cin >> c;
    cin >> c;
    if (tar != c) {
      if (cur) {
        lt[++n] = cur;
        ct[n] = tar;
      }
      tar = c;
      cur = l;
    } else
      cur += l;
  }
  if (cur) {
    lt[++n] = cur;
    ct[n] = tar;
  }
  tar = '?';
  cur = 0;
  for (long long i = 1; i <= mm; ++i) {
    long long l;
    char c;
    cin >> l;
    cin >> c;
    cin >> c;
    if (tar != c) {
      if (cur) {
        ls[m] = cur;
        cs[m++] = tar;
      }
      tar = c;
      cur = l;
    } else
      cur += l;
  }
  if (cur) {
    ls[m] = cur;
    cs[m++] = tar;
  }
  m--;
  if (m == 0) {
    long long ans = 0;
    for (long long i = 1; i <= n; ++i)
      if (lt[i] >= ls[0] && ct[i] == cs[0]) ans += (lt[i] - ls[0] + 1);
    cout << ans << endl;
    return 0;
  } else if (m == 1) {
    long long ans = 0;
    for (long long i = 1; i < n; ++i)
      if (lt[i] >= ls[0] && ct[i] == cs[0] && lt[i + 1] >= ls[1] &&
          ct[i + 1] == cs[1])
        ans++;
    cout << ans << endl;
    return 0;
  } else {
    for (long long i = 2, j = 0; i <= m - 1; ++i) {
      while (j && (ls[j + 1] != ls[i] || cs[j + 1] != cs[i])) j = ne[j];
      if (ls[j + 1] == ls[i] && cs[j + 1] == cs[i]) ++j;
      ne[i] = j;
    }
    long long ans = 0;
    for (long long i = 1, j = 0; i <= n; ++i) {
      while (j && (ls[j + 1] != lt[i] || cs[j + 1] != ct[i])) j = ne[j];
      if (ls[j + 1] == lt[i] && cs[j + 1] == ct[i]) ++j;
      if (j == m - 1) {
        if (i > 1 && i < n && ct[i - 1] == cs[0] && ct[i + 1] == cs[m] &&
            lt[i - 1] >= ls[0] && lt[i + 1] >= ls[m])
          ans++;
        j = ne[j];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
