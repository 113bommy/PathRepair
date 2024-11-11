#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
template <class T>
void read(T &x) {
  char ch;
  bool neg = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar()) neg = ch == '-';
  x = ch - '0';
  for (ch = getchar(); isdigit(ch); ch = getchar()) (x *= 10) += ch - '0';
  x *= neg ? -1 : 1;
}
template <class T, class... Args>
void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
template <class T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
void writei(T x) {
  write(x);
  putchar(' ');
}
template <class T>
void writeln(T x) {
  write(x);
  putchar('\n');
}
template <class T, class... Args>
void write(T x, Args &...args) {
  writei(x);
  writei(args...);
}
int a[N];
int t = 1;
void solve() {
  int n;
  read(n);
  for (int i = 1; i <= n; i++) {
    int tmp;
    read(tmp);
    for (int j = 30; j >= 0; j--) {
      if ((1 << j) & tmp) {
        a[i] = j;
        break;
      }
    }
  }
  sort(a + 1, a + 1 + n);
  long long ans = 0;
  int cur = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      ans += i - cur;
    } else {
      cur = i;
    }
  }
  writeln(ans);
}
int main() {
  if (fopen("..."
            ".inp",
            "r")) {
    freopen(
        "..."
        ".inp",
        "r", stdin);
    freopen(
        "..."
        ".out",
        "w", stdout);
  }
  read(t);
  while (t--) {
    solve();
  }
}
