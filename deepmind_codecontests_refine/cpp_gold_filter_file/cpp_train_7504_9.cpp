#include <bits/stdc++.h>
using namespace std;
void use_cio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
template <typename... Args>
void dbg(Args... args) {
  ((cout << args << " "), ...);
  cout << endl;
}
int n;
int ask(int r1, int c1, int r2, int c2) {
  string ans;
  dbg("?", r1, c1, r2, c2);
  cout.flush();
  cin >> ans;
  return (ans == "YES");
}
int main() {
  cin >> n;
  string l, r;
  int sx = 1, sy = 1;
  while (sx + sy < n + 1) {
    if (sy + 1 <= n && ask(sx, sy + 1, n, n)) {
      sy++;
      l += 'R';
    } else {
      sx++;
      l += 'D';
    }
  }
  int ex = n, ey = n;
  while (ex + ey > n + 1) {
    if (ex && ask(1, 1, ex - 1, ey)) {
      ex--;
      r += 'D';
    } else {
      ey--;
      r += 'R';
    }
  }
  reverse(r.begin(), r.end());
  dbg("!", l + r);
}
