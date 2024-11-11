#include <bits/stdc++.h>
using namespace std;
int n, x[4];
bool test() {
  int t[4];
  for (int i = 0; i < 4; ++i) t[i] = x[i];
  sort(t, t + 4);
  return (t[3] - t[0]) * 2 == (t[1] + t[2]) &&
         (t[3] - t[0]) * 4 == t[0] + t[1] + t[2] + t[3];
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i];
  if (n == 0) cout << "YES\n1\n1\n3\n3";
  if (n == 1) cout << "YES\n" << x[0] << '\n' << 3 * x[0] << '\n' << 3 * x[0];
  if (n == 2) {
    for (int i = 1; i < 1500; ++i)
      for (int j = i; j < 1500; ++j) {
        x[2] = i;
        x[3] = j;
        if (test()) {
          cout << "YES\n" << i << '\n' << j;
          return 0;
        }
      }
    cout << "NO";
  }
  if (n == 3) {
    for (int i = 1; i < 10000; ++i) {
      x[3] = i;
      if (test()) {
        cout << "YES\n" << i;
        return 0;
      }
    }
    cout << "NO";
  }
  if (n == 4) {
    if (test())
      cout << "YES";
    else
      cout << "NO";
  }
}
