#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  int fh = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= fh;
}
int n, k, t, x, y;
int main() {
  cin >> n >> k >> t >> t;
  while (t--) {
    cin >> x >> y;
    if (x == 1) {
      n++;
      if (k <= y) k++;
    } else {
      if (k > y) {
        k -= y;
        n -= y;
      } else {
        n = y;
      }
    }
    cout << n << ' ' << k << endl;
  }
  return 0;
}
