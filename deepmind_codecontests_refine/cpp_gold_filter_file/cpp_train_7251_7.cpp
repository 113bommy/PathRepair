#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  int h[n], m[n], t[n + 1], c[n];
  t[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i] >> m[i];
    t[i + 1] = h[i] * 60 + m[i];
    c[i] = t[i + 1] - t[i];
  }
  if (c[0] > s) {
    int a = t[0] + s + 1;
    cout << 0 << " " << 0;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (c[i] > s * 2 + 1) {
      int a = t[i] + s + 1;
      cout << a / 60 << " " << a % 60;
      return 0;
    }
  }
  int a = t[n] + s + 1;
  cout << a / 60 << " " << a % 60;
  return 0;
}
