#include <bits/stdc++.h>
using namespace std;
int n = 4;
int f(int a, int b, int c, int d) {
  if (b > n || a == 0) {
    return 0;
  }
  cout << "? " << a << " " << b << " " << c << " " << d << "\n";
  cout.flush();
  string s;
  cin >> s;
  if (s == "NO") {
    return 0;
  } else {
    return 1;
  }
}
void solve() {
  cin >> n;
  int x = 1, y = 1;
  string s = "";
  int a = n, b = n;
  for (int i = 0; i < n - 1; i++) {
    if (f(x, y + 1, n, n)) {
      s += 'R';
      y++;
    } else {
      s += 'D';
      x++;
    }
  }
  string t = "";
  x = n;
  y = n;
  for (int i = 0; i < n - 1; i++) {
    if (f(x - 1, y, 1, 1)) {
      x--;
      t += 'D';
    } else {
      y--;
      t += 'R';
    }
  }
  reverse(t.begin(), t.end());
  cout << "! " << s << t << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) solve();
}
