#include <bits/stdc++.h>
using namespace std;
inline void read(int &first) {
  register int c = getchar();
  first = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    first = (first << 1) + (first << 3) + c - 48;
  }
  if (neg) first = -first;
}
inline void read(long long &first) {
  register int c = getchar();
  first = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    first = (first << 1) + (first << 3) + c - 48;
  }
  if (neg) first = -first;
}
inline void writeln(long long first) {
  char buffor[21];
  register int i = 0;
  int neg = 0;
  if (first < 0) {
    neg = 1;
    first = -first;
  }
  do {
    buffor[i++] = (first % 10) + '0';
    first /= 10;
  } while (first);
  i--;
  if (neg) putchar('-');
  while (i >= 0) putchar(buffor[i--]);
  putchar('\n');
}
inline void write(long long first) {
  char buffor[21];
  register int i = 0;
  int neg = 0;
  if (first < 0) {
    neg = 1;
    first = -first;
  }
  do {
    buffor[i++] = (first % 10) + '0';
    first /= 10;
  } while (first);
  i--;
  if (neg) putchar('-');
  while (i >= 0) putchar(buffor[i--]);
  putchar(' ');
}
const int N = 1e2 + 7;
string s, t, virus;
int m, n, v;
int f[N][N][N];
int KMP[N];
int nxt[N][2 * N];
void trace(int m, int n, int k) {
  if (m == 0 && n == 0 && k == 0) return;
  if (m && f[m][n][k] == f[m - 1][n][k]) {
    trace(m - 1, n, k);
    return;
  }
  if (n && f[m][n][k] == f[m][n - 1][k]) {
    trace(m, n - 1, k);
    return;
  }
  for (int i = 0; i < v; i++)
    if (nxt[i][s[m]] == k && f[m][n][k] == f[m - 1][n - 1][i] + 1) {
      trace(m - 1, n - 1, i);
      break;
    }
  putchar(s[m]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  cin >> t;
  cin >> virus;
  m = s.size();
  n = s.size();
  v = virus.size();
  s = ' ' + s;
  t = ' ' + t;
  virus = ' ' + virus;
  int id = 0;
  for (int i = 2; i <= v; i++) {
    while (id && virus[id + 1] != virus[i]) id = KMP[id];
    if (virus[id + 1] == virus[i]) id++;
    KMP[i] = id;
  }
  for (int i = 0; i < v; i++) {
    for (int ch = 'A'; ch <= 'Z'; ch++) {
      id = i;
      while (id && virus[id + 1] != ch) id = KMP[id];
      if (virus[id + 1] == ch) id++;
      nxt[i][ch] = id;
    }
  }
  memset(f, -1, sizeof(f));
  f[0][0][0] = 0;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k < v; k++)
        if (f[i][j][k] >= 0) {
          if (i < m) f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k]);
          if (j < n) f[i][j + 1][k] = max(f[i][j + 1][k], f[i][j][k]);
          if (i < m && j < n && s[i + 1] == t[j + 1])
            f[i + 1][j + 1][nxt[k][s[i + 1]]] =
                max(f[i + 1][j + 1][nxt[k][s[i + 1]]], f[i][j][k] + 1);
        }
  int res = 0;
  for (int i = 0; i < v; i++)
    if (f[m][n][i] > f[m][n][id]) id = i;
  res = f[m][n][id];
  if (res == 0) {
    cout << 0;
    return 0;
  }
  trace(m, n, id);
}
