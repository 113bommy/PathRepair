#include <bits/stdc++.h>
using namespace std;
void create(int n, int a[]) {
  if (n == 1) {
    a[1] = 1;
    return;
  }
  if (n == 2) {
    a[1] = 3;
    a[2] = 4;
    return;
  }
  if (n & 1) {
    a[1] = 2;
    for (int i = 2; i < n; ++i) {
      a[i] = 1;
    }
    a[n] = (n + 1) / 2;
  } else {
    for (int i = 1; i < n; ++i) {
      a[i] = 1;
    }
    a[n] = (n - 2) / 2;
  }
}
int a[105];
int b[105];
int main() {
  ios::sync_with_stdio(false);
  int m, n;
  cin >> n >> m;
  create(n, a);
  create(m, b);
  for (int i = 1; i <= n; ++i) {
    for (int t = 1; t <= m; ++t) {
      cout << a[i] * b[t] << ' ';
    }
    cout << endl;
  }
  return 0;
}
