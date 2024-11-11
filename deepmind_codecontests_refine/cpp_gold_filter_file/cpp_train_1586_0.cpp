#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[105], p[105], b[105];
bool c[105];
void go(int x, int y) {
  memset(c, 0, sizeof c);
  for (int i = 0; i < x; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a + 0, a + x);
  for (int i = 0; i < y; i++) {
    cin >> p[i];
    c[p[i]] = 1;
  }
  for (int i = 0; i < x; i++) {
    if (a[i] == b[i]) {
      continue;
    }
    if (b[i] > a[i]) {
      for (int j = i; j < x; j++) {
        if (a[j] == b[i]) {
          break;
        }
        if (c[j + 1] == 0) {
          cout << "NO" << endl;
          return;
        }
      }
    } else {
      for (int j = i; j >= 0; j--) {
        if (a[j] == b[i]) break;
        if (c[j] == 0) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    go(n, m);
  }
}
