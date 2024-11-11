#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, c = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    int t = 0;
    t = i * (i + 1) / 2;
    if (t == n) {
      c = 1;
      break;
    }
  }
  if (c == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
