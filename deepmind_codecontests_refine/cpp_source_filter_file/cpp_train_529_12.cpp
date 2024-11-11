#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
int n, s, a;
int t[100001];
int l[100001];
int main() {
  int ans = 0;
  read(n);
  read(s);
  read(a);
  for (int i = (1); i <= (n); i++) {
    read(t[i]);
    read(l[i]);
    ans += (t[i] - t[i - 1] - 1) / a;
    t[i] += l[i];
  }
  ans += (s - t[n]) / a;
  writeln(ans);
}
