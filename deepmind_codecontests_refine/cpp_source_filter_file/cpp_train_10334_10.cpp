#include <bits/stdc++.h>
inline int in();
inline void wr(int);
inline bool vowel(char);
const int N = (int)1e4 + 5;
std::string ss[N];
int main(int argc, char** argv) {
  register int n = in(), k = in();
  n *= 4;
  register int len = 0;
  for (register int i = 1; i <= n; ++i) {
    std::string s;
    std::cin >> s;
    register int j = 0;
    for (register int l = s.size() - 1; l >= 0; --l) {
      if (vowel(s[l])) ++j;
      if (j >= k) {
        ss[++len] = s.substr(l);
        break;
      }
    }
  }
  if (len < n) {
    puts("NO");
    return 0;
  }
  std::string res = "aaaa";
  for (register int i = 1; i <= n; i += 4) {
    std::string tmp;
    register bool tp1 = ss[i] == ss[i + 1];
    register bool tp2 = ss[i + 1] == ss[i + 2];
    register bool tp3 = ss[i + 2] == ss[i + 3];
    if (tp1 && tp2 && tp3)
      tmp = "aaaa";
    else if (tp1 && ss[i + 2] == ss[i + 3])
      tmp = "aabb";
    else if (tp2 && ss[i + 1] == ss[i + 3])
      tmp = "abab";
    else if (tp3 && ss[i + 1] == ss[i + 2])
      tmp = "abba";
    else
      tmp = "NO";
    if (res == "aaaa")
      res = tmp;
    else if (res == tmp || tmp == "aaaa")
      ;
    else
      res = "NO";
  }
  std::cout << res << std::endl;
}
inline bool vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
inline int in() {
  register char c = getchar();
  register int x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (x << 1) + (x << 3) + (c & 15);
  return x * f;
}
inline void wr(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x / 10) wr(x / 10);
  putchar(x % 10 + '0');
}
