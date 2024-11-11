#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int done = 0;
  int i, f = 0, s = 0;
  for (i = 0; i <= n / 7; i++) {
    if ((n - i * 7) % 4 == 0) {
      done = 1;
      s = i;
      f = (n - i * 7) / 4;
    }
  }
  if (!done)
    cout << -1;
  else {
    for (i = 0; i < f; i++) cout << 4;
    for (i = 0; i < s; i++) cout << 7;
  }
  return 0;
}
