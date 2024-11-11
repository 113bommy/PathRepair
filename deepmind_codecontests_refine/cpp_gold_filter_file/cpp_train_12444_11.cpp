#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int l = 1, ans = 1, n;
  a[0] = 1;
  char c;
  while (cin >> c && c != '=') {
    if (c == '+') {
      a[l++] = 1;
      ans++;
    }
    if (c == '-') {
      a[l++] = -1;
      ans--;
    }
  }
  cin >> n;
  for (int i = 0; i < l; i++) {
    if (a[i] > 0) {
      while (ans < n && a[i] < n) {
        a[i]++;
        ans++;
      }
    }
    if (a[i] < 0) {
      while (ans > n && a[i] > -n) {
        a[i]--;
        ans--;
      }
    }
  }
  if (ans != n) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  cout << a[0];
  for (int i = 1; i < l; i++) {
    cout << " " << (a[i] > 0 ? "+" : "-") << " " << abs(a[i]);
  }
  cout << " = " << n << endl;
}
