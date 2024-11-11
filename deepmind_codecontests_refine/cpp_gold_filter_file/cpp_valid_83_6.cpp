#include <bits/stdc++.h>
inline char gc() {
  static const int L = 233333;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) {
      return EOF;
    }
  }
  return *sss++;
}
template <class T>
inline bool read(T& x) {
  x = 0;
  char c = gc();
  bool flg = false;
  for (; !isdigit(c); c = gc()) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); c = gc()) {
    x = (x * 10) + (c ^ 48);
  }
  if (flg) {
    x = -x;
  }
  return true;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) {
    write(x / 10);
    x %= 10;
  }
  putchar(x | 48);
}
template <class T>
inline void writeln(T x) {
  write(x);
  puts("");
}
template <class T>
inline void writesp(T x) {
  write(x);
  putchar(' ');
}
std::vector<int> Z_function(std::string s) {
  int n = s.length();
  std::vector<int> z(n);
  z[0] = n;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = std::max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        z[i]++;
      }
    }
    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  return z;
}
void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector<int> f(n);
  for (int i = n - 1; ~i; --i) {
    auto z = Z_function(s.substr(i));
    f[i] = n - i;
    for (int j = i + 1; j < n; ++j) {
      int lcp = z[j - i];
      if (j + lcp < n && s[i + lcp] < s[j + lcp]) {
        f[i] = std::max(f[i], f[j] - lcp + n - i);
      }
    }
  }
  std::cout << *std::max_element(f.begin(), f.end()) << std::endl;
}
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
