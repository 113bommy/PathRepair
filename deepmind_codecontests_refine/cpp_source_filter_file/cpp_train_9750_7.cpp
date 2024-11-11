#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
string s, t;
string a, b;
int ans[125001];
int n, m;
int gr[256];
char value[256];
int f[125001];
void make(int cost) {
  for (int i = ('f'); i >= ('a'); i--) value[gr[i]] = i;
  a = b = "";
  for (char c : s) a += value[gr[c]];
  for (char c : t) b += value[gr[c]];
  f[1] = 0;
  for (int i = (2); i <= (m); i++) {
    f[i] = f[i - 1];
    while ((f[i] > 0) && (b[f[i] + 1] != b[i])) f[i] = f[f[i]];
    if (f[i] + 1 == b[i]) f[i]++;
  }
  int pos = 0;
  for (int i = (1); i <= (n); i++) {
    if (b[pos + 1] == a[i])
      pos++;
    else {
      while ((pos > 0) && (b[f[pos] + 1] != a[i])) pos = f[pos];
      if (b[f[pos] + 1] == a[i]) pos++;
    }
    if (pos == m) {
      ans[i] = min(ans[i], cost);
      pos = f[pos];
    }
  }
}
void backtrack(char c, int high) {
  if (c == 'g')
    make('f' - 'a' + 1 - high);
  else {
    for (int i = (1); i <= (high + 1); i++) {
      gr[c] = i;
      backtrack(c + 1, max(high, i));
    }
  }
}
int main() {
  cin >> s >> t;
  n = s.size();
  m = t.size();
  for (int i = (1); i <= (n); i++) ans[i] = 5;
  s = '0' + s;
  t = '0' + t;
  backtrack('a', 0);
  for (int i = (m); i <= (n); i++) write(ans[i]), putchar(' ');
}
