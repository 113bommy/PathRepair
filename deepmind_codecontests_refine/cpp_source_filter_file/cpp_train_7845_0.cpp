#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto const &vv : V) os << vv << ",";
  os << "]";
  return os;
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  os << "(" << P.first << "," << P.second << ")";
  return os;
}
template <typename T>
inline void print_128(T num) {
  if (!num) return;
  print_128(num / 10);
  cout.put((num % 10) + '0');
}
inline int fstoi(const string &str) {
  auto it = str.begin();
  bool neg = 0;
  int num = 0;
  if (*it == '-')
    neg = 1;
  else
    num = *it - '0';
  ++it;
  while (it < str.end()) num = num * 10 + (*it++ - '0');
  if (neg) num *= -1;
  return num;
}
inline void getch(char &x) {
  while (x = getchar_unlocked(), x < 33) {
    ;
  }
}
inline void getstr(string &str) {
  str.clear();
  char cur;
  while (cur = getchar_unlocked(), cur < 33) {
    ;
  }
  while (cur > 32) {
    str += cur;
    cur = getchar_unlocked();
  }
}
template <typename... Args>
inline void getstr(string &str, Args &...arg) {
  str.clear();
  char cur;
  while (cur = getchar_unlocked(), cur < 33) {
    ;
  }
  while (cur > 32) {
    str += cur;
    cur = getchar_unlocked();
  }
  getstr(arg...);
}
template <typename T>
inline bool sc(T &num) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    if (c == EOF) return false;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  return true;
}
template <typename T, typename... Args>
inline void sc(T &num, Args &...args) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    ;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  sc(args...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  sc(t);
  int n;
  while (t--) {
    sc(n);
    bool g = 0;
    for (int i = (3); i < int((180)); ++i) {
      int tmp = (i - 2) * 180;
      if (tmp % i) continue;
      if (tmp / i == n) {
        g = 1;
        break;
      }
    }
    cout << (g ? "YES" : "NO") << '\n';
  }
}
