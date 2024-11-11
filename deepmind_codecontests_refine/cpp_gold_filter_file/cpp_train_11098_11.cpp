#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
int T, n, k, u, v;
char a, b;
char str[5] = "^>v<";
void solve() {
  int st = 0, en = 0;
  for (int i = 0; i < 4; i++) {
    if (str[i] == a) {
      st = i;
      break;
    }
  }
  if (str[(st + n) % 4] == b && str[((st - n) % 4 + 4) % 4] == b) {
    cout << "undefined" << endl;
  } else if (str[(st + n) % 4] == b) {
    cout << "cw" << endl;
  } else if (str[((st - n) % 4 + 4) % 4] == b) {
    cout << "ccw" << endl;
  } else
    cout << "undefined" << endl;
}
int main() {
  scanf(" %c %c %d", &a, &b, &n);
  solve();
  return 0;
}
