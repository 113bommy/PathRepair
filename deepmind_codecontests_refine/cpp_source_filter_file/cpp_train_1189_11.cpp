#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int u = n + 1;
  int v = n;
  if (((m / 2 + m % 2) > u || v > m) && n != m + 1) {
    cout << -1 << endl;
    return 0;
  }
  if (n == m + 1) {
    while (n > 0) {
      cout << 0 << 1;
      n--;
    }
    cout << 0;
    return 0;
  } else if (u <= m) {
    int ts = m - u;
    int os = m - 2 * ts;
    while (u > 0) {
      if (os > 0) {
        cout << 1;
        os--;
      } else {
        cout << 11;
        ts--;
      }
      if (n > 0) {
        cout << 0;
        n--;
      }
      u--;
    }
  } else if (u > m && v <= m) {
    int ts = m - v;
    int os = m - 2 * ts;
    while (v > 0) {
      if (os > 0) {
        cout << 1;
        os--;
      } else {
        cout << 11;
        ts--;
      }
      if (n > 0) {
        cout << 0;
        n--;
      }
      v--;
    }
  }
  return 0;
}
