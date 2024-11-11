#include <bits/stdc++.h>
using namespace std;
char inline nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <typename T>
bool rd(T& v) {
  static char ch;
  while (ch != EOF && !isdigit(ch)) ch = nc();
  if (ch == EOF) return false;
  for (v = 0; isdigit(ch); ch = nc()) v = v * 10 + ch - '0';
  return true;
}
template <typename T>
void o(T p) {
  static int stk[70], tp;
  if (p == 0) {
    putchar('0');
    return;
  }
  if (p < 0) {
    p = -p;
    putchar('-');
  }
  while (p) stk[++tp] = p % 10, p /= 10;
  while (tp) putchar(stk[tp--] + '0');
}
const int maxn = 2e5 + 5;
const int maxm = 4e5 + 5;
const int inf = 1e9;
int main() {
  int n;
  cin >> n;
  if (n & 1) {
    puts("NO");
    return 0;
  }
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  int l = 0, r = n / 2;
  if (1) {
    int cnt = n / 2;
    bool ok = 1;
    for (int i = 1; i < cnt; i++) {
      int nx1 = i + l, nx2 = i + r;
      if (p[nx1].first - p[l].first + p[nx2].first - p[r].first != 0 ||
          p[nx1].second - p[l].second + p[nx2].second - p[r].second != 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}
