#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void out(T a) {
  int i = 0;
  char s[20];
  if (a == 0) s[i++] = '0';
  if (a < 0) putchar('-'), a = -a;
  while (a > 0) s[i++] = a % 10 + '0', a /= 10;
  --i;
  while (i >= 0) putchar(s[i--]);
  putchar(' ');
}
inline void out(char a) { putchar(a); }
inline void out(const char *s) {
  int n = strlen(s);
  for (int i = 0; i < n; i++) putchar(s[i]);
}
inline void out(char *s) {
  int n = strlen(s);
  for (int i = 0; i < n; i++) putchar(s[i]);
}
inline void out(string s) {
  int n = s.length();
  for (int i = 0; i < n; i++) putchar(s[i]);
}
inline void out(double n) { printf("%.15lf ", n); }
inline void out() { putchar('\n'); }
inline void in(double &n) { scanf("%lf", &n); }
template <typename T>
inline void in(T &n) {
  register T c = getchar();
  n = 0;
  bool neg = false;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') neg = true, c = getchar();
  for (; (c > 47 && c < 58); c = getchar()) n = (n << 1) + (n << 3) + c - 48;
  if (neg) n *= -1;
}
inline void in(char &a) {
  while (a < 33) a = getchar();
}
inline void in(char *s) {
  register char c = 0;
  register int i = 0;
  while (c < 33) c = getchar();
  while (c != '\n') s[i] = c, c = getchar(), i++;
  s[i] = '\0';
}
inline void in(string &s) {
  register char c = 0;
  s = "";
  while (c < 33) c = getchar();
  while (c != '\n') s += c, c = getchar();
}
const int MAXN = 1e5 + 5;
int main() {
  string s;
  in(s);
  int n = s.length();
  bool ans = true;
  vector<int> v;
  for (int i = 0; i < n; i++)
    if (s[i] == '.') v.push_back(i);
  if (v.size() == 0 || v[0] <= 0 || v[0] >= 8 || n - v[v.size() - 1] - 1 <= 0 ||
      n - v[v.size() - 1] - 1 > 3)
    ans = false;
  for (int i = 1; i < v.size(); i++)
    if (v[i] - v[i - 1] - 1 > 11 || v[i] - v[i - 1] - 1 < 2) {
      ans = false;
      break;
    }
  if (!ans) {
    out("NO"), out();
    return 0;
  }
  out("YES"), out();
  int prev = 0;
  string loc;
  for (int i = 0; i < v.size(); i++) {
    if (i == v.size() - 1) {
      loc = s.substr(prev, n - prev);
      out(loc), out();
      continue;
    }
    int len = v[i + 1] - v[i] - 1;
    if (len > 3)
      loc = s.substr(prev, v[i] + 4 - prev), prev = v[i] + 4;
    else if (len == 3)
      loc = s.substr(prev, v[i] + 3 - prev), prev = v[i] + 3;
    else if (len == 2)
      loc = s.substr(prev, v[i] + 2 - prev), prev = v[i] + 2;
    out(loc), out();
  }
  return 0;
}
