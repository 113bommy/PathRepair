#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void cmax(T &x, T y) {
  x < y ? x = y : x;
}
template <typename T>
inline void cmin(T &x, T y) {
  y < x ? x = y : x;
}
char bf[1 << 21], *p1(bf), *p2(bf);
template <typename T>
inline void read(T &x) {
  char t(
      (p1 == p2 && (p1 = bf, p2 = bf + fread(bf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++)),
      flg(0);
  x = 0;
  for (; !isdigit(t);
       t = (p1 == p2 &&
                    (p1 = bf, p2 = bf + fread(bf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++))
    flg = t == '-';
  for (; isdigit(t);
       t = (p1 == p2 &&
                    (p1 = bf, p2 = bf + fread(bf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++))
    x = x * 10 + (t & 15);
  flg ? x = -x : x;
}
int T;
string s1, s2;
int s[5015];
int main() {
  cin >> T;
  while (T--) {
    cin >> s1 >> s2;
    s[s1.size()] = s1.size() - 1;
    for (int i(s1.size() - 1), I(0); i >= I; --i) {
      if (s1[i] > s1[s[i + 1]])
        s[i] = s[i + 1];
      else
        s[i] = i;
    }
    for (int i(0), I(s1.size() - 1); i <= I; ++i) {
      if (s1[i] > s1[s[i]]) {
        swap(s1[i], s1[s[i]]);
        break;
      }
    }
    if (s1 < s2)
      cout << s1 << endl;
    else
      cout << "---\n";
  }
  return 0;
}
