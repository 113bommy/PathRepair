#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b, i, d, cn = 1;
  cin >> n >> a >> b;
  if (b == 0) {
    cout << a << endl;
    return 0;
  } else if (b < 0) {
    d = -1;
    if (a == 1)
      i = n;
    else
      i = a - 1;
    if (b == -1) {
      cout << i << endl;
      return 0;
    }
  } else if (b > 0) {
    d = 1;
    i = a + 1;
    if (a + 1 > n) i = n;
    if (b == 1) {
      cout << i << endl;
      return 0;
    }
  }
  while (1) {
    i += d;
    cn++;
    if (i == 0 && d == -1) {
      i = n;
    }
    if (i == n + 1 && d == 1) {
      i = a;
    }
    if (cn == abs(b)) break;
  }
  cout << i << endl;
  return 0;
}
