#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y;
  friend bool operator==(node a, node b) {
    if (a.x == b.x && a.y == b.y) return true;
    return false;
  }
  friend bool operator!=(node a, node b) {
    if (a.x == b.x && a.y == b.y) return false;
    return true;
  }
};
struct line {
  node st, ed;
};
bool flag;
bool check(node a, node b, node c) {
  long long x1, y1, x2, y2;
  x1 = b.x - a.x;
  y1 = b.y - a.y;
  x2 = c.x - a.x;
  y2 = c.y - a.y;
  long long ans = x1 * x2 + y1 * y2;
  if (ans >= 0) return true;
  return false;
}
bool check2(node a, node b, node c) {
  if ((b.x - a.x) * (c.y - a.y) == (c.x - a.x) * (b.y - a.y)) return true;
  return false;
}
bool dis(long long x, long long y, long long m, long long n, long long a,
         long long b) {
  if (x != a) {
    if (a > x) {
      if ((a - x) * 5 < (m - x)) return 0;
      if ((a - x) * 5 > (m - x) * 4) return 0;
      return 1;
    } else {
      if ((x - a) * 5 < (x - m)) return 0;
      if ((x - a) * 5 > (x - m) * 4) return 0;
      return 1;
    }
  } else {
    if (b > y) {
      if ((b - y) * 5 < (n - y)) return 0;
      if ((b - y) * 5 > (n - y) * 4) return 0;
      return 1;
    } else {
      if ((y - b) * 5 < (y - n)) return 0;
      if ((y - b) * 5 > (y - n) * 4) return 0;
      return 1;
    }
  }
  return 0;
}
void solve(line a, line b, line c) {
  if (a.st == b.ed) swap(b.st, b.ed);
  if (a.ed == b.st) swap(a.st, a.ed);
  if (a.ed == b.ed) {
    swap(a.st, a.ed);
    swap(b.st, b.ed);
  }
  if (a.st != b.st) return;
  if (!check(a.st, a.ed, b.ed)) return;
  if (check2(c.st, a.st, a.ed) && check2(c.ed, b.st, b.ed)) {
    if (!dis(a.st.x, a.st.y, a.ed.x, a.ed.y, c.st.x, c.st.y)) return;
    if (!dis(b.st.x, b.st.y, b.ed.x, b.ed.y, c.ed.x, c.ed.y)) return;
    flag = true;
  }
  if (check2(c.st, b.st, b.ed) && check2(c.ed, a.st, a.ed)) {
    if (!dis(a.st.x, a.st.y, a.ed.x, a.ed.y, c.ed.x, c.ed.y)) return;
    if (!dis(b.st.x, b.st.y, b.ed.x, b.ed.y, c.st.x, c.st.y)) return;
    flag = true;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    line a, b, c;
    cin >> a.st.x >> a.st.y >> a.ed.x >> a.ed.y;
    cin >> b.st.x >> b.st.y >> b.ed.x >> b.ed.y;
    cin >> c.st.x >> c.st.y >> c.ed.x >> c.ed.y;
    flag = false;
    solve(a, b, c);
    solve(a, c, b);
    solve(b, c, a);
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
