#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807;
void doh() { cout << "IMPOSSIBLE", exit(0); }
int main() {
  int n, m, a, b, c;
  cin >> n >> m >> a >> b >> c;
  if (n % 2 == 1 && m % 2 == 1) doh();
  bool rev = false;
  if (n % 2 == 1) swap(n, m), swap(a, b), rev = true;
  char arr[110][110];
  if (m % 2 == 1) {
    if (b < n / 2) doh();
    b -= n / 2;
    for (int i = 0; i < n; ++i) {
      if ((i / 2) % 2)
        arr[i][m - 1] = 'x';
      else
        arr[i][m - 1] = 'y';
    }
  }
  for (int i = 0; i < n / 2; ++i) {
    char c1, c2, c1d, c2d;
    if (i % 2)
      c1 = 'a', c2 = 'b', c1d = 'g', c2d = 'h';
    else
      c1 = 'c', c2 = 'd', c1d = 'e', c2d = 'f';
    for (int j = 0; j < m / 2; ++j) {
      if (c > 0) {
        arr[2 * i][2 * j] = c1;
        arr[2 * i + 1][2 * j] = c1;
        arr[2 * i][2 * j + 1] = c1;
        arr[2 * i + 1][2 * j + 1] = c1;
        c--;
      } else if (b >= 2) {
        arr[2 * i][2 * j] = c1;
        arr[2 * i + 1][2 * j] = c1;
        arr[2 * i][2 * j + 1] = c2;
        arr[2 * i + 1][2 * j + 1] = c2;
        b -= 2;
      } else if (a >= 2) {
        arr[2 * i][2 * j] = c1;
        arr[2 * i + 1][2 * j] = c2;
        arr[2 * i][2 * j + 1] = c1;
        arr[2 * i + 1][2 * j + 1] = c2;
        a -= 2;
      } else
        doh();
      swap(c1, c1d);
      swap(c2, c2d);
    }
  }
  if (rev) swap(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (rev)
        cout << arr[j][i];
      else
        cout << arr[i][j];
    }
    cout << endl;
  }
  return 0;
}
