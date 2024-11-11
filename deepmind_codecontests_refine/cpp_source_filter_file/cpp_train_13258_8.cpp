#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, n;
  cin >> s >> n;
  int x[n], y[n], p[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    cin >> y[i];
    p[i] = x[i];
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    int k = p[i];
    if (k == 100000) {
      break;
    }
    for (int j = 0; j < n; j++) {
      if (x[i] == k) {
        if (k < s) {
          s = s + y[i];
        } else {
          cout << "NO" << endl;
          exit(0);
        }
        x[i] = 100000;
      }
    }
  }
  cout << "YES" << endl;
}
