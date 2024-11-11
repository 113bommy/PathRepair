#include <bits/stdc++.h>
using namespace std;
void enable_comma() {}
string tostring(char c) {
  string s = "";
  s += c;
  return s;
}
string tostring(string s) { return "\"" + s + "\""; }
string tostring(const char *c) { return tostring((string)c); }
string tostring(long long x) {
  if (x < 0) return "-" + tostring(-x);
  if (x > 9)
    return tostring(x / 10) + tostring(char('0' + x % 10));
  else
    return tostring(char('0' + x));
}
string tostring(int x) { return tostring((long long)x); }
string tostring(unsigned long long x) {
  if (x > 9)
    return tostring((long long)(x / 10)) + tostring(char('0' + x % 10));
  else
    return tostring(char('0' + x));
}
string tostring(unsigned x) { return tostring((long long)x); }
string tostring(double x) {
  static char res[114];
  sprintf(res, "%lf", x);
  string s = tostring(res);
  return s.substr(1, (int)s.size() - 2);
}
string tostring(long double x) { return tostring((double)x); }
template <class A, class B>
string tostring(pair<A, B> p) {
  return "(" + tostring(p.first) + "," + tostring(p.second) + ")";
}
template <class T>
string tostring(T v) {
  string res = "";
  for (auto p : v) res += (res.size() ? "," : "{") + tostring(p);
  return res.size() ? res + "}" : "{}";
}
template <class A>
string tostring(A *a, int L, int R) {
  return tostring(vector<A>(a + L, a + R + 1));
};
template <class A>
string tostring(A a, int L, int R) {
  return tostring(a.data(), L, R);
}
string tostrings() { return ""; }
template <typename Head, typename... Tail>
string tostrings(Head H, Tail... T) {
  return tostring(H) + " " + tostrings(T...);
}
long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <class T>
void ckmax(T &x, const T y) {
  if (x < y) x = y;
}
template <class T>
void ckmin(T &x, const T y) {
  if (x > y) x = y;
}
const int N = 500005;
int n, mx;
long long tot;
int a[N];
int p[N];
int check1(int x, int y) {
  x *= 2;
  int c = mx / y;
  int vx = x / y, rx = x % y;
  if (x > a[n]) return 0;
  int now = tot - vx;
  if (now > x / 2) return 1;
  int cnt = 0;
  for (int i = (1); i <= (c + 1); i++) {
    int j = p[i];
    if (j > 1 && a[j - 1] >= x && a[j - 1] % y >= rx) {
      cnt = 1;
    }
  }
  enable_comma();
  return now - 1 + cnt >= x / 2;
}
int vis[N], Time = 0;
int check(int x, int y) {
  if (check1(x, y)) return 1;
  if (n == 1 || x > a[n - 1]) return 0;
  enable_comma();
  int c = mx / y;
  int vx = x / y, rx = x % y;
  long long now = tot - vx * 2;
  if (now >= x + 2) return 1;
  int cnt = 0;
  Time++;
  for (int i = (1); i <= (c + 1); i++) {
    for (int j = (p[i] - 1); j <= (p[i]); j++)
      if (j > 1 && vis[j - 1] != Time && a[j - 1] >= x && a[j - 1] % y >= rx) {
        cnt++, vis[j - 1] = Time;
      }
  }
  return now - 2 + min(cnt, 2) >= x;
}
int main() {
  n = read();
  for (int i = (1); i <= (n); i++) a[i] = read();
  sort(a + 1, a + n + 1);
  mx = a[n];
  long long ans = 0;
  for (int y = (2); y <= (mx); y++) {
    tot = 0;
    for (int i = (1); i <= (mx / y); i++) {
      p[i] = lower_bound(a + 1, a + n + 1, i * y) - a;
      tot += n - p[i] + 1;
    }
    enable_comma();
    enable_comma();
    p[mx / y + 1] = n + 1;
    enable_comma();
    int L = 2, R = mx;
    while (L <= R) {
      int k = (L + R) >> 1;
      if (check(k, y))
        L = k + 1, ckmax(ans, (long long)k * y);
      else
        R = k - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
