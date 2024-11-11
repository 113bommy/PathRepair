#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, s;
  cin >> n;
  int v[70000] = {0};
  for (int c = 0; c < n; c++) {
    cin >> k >> s;
    v[k + 30000] = s;
  }
  int ban = 0;
  for (int c = 0; c < 70000; c++) {
    if (c + v[c] >= 0 && v[c] != 0) {
      if (v[c + v[c]] == -1 * v[c]) {
        cout << "YES";
        ban = 1;
        break;
      }
    }
  }
  if (ban == 0) cout << "NO";
}
