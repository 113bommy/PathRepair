#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, a[1010], c = 0;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    if (a[0] == 0)
      cout << "NO";
    else
      cout << "YES";
  } else {
    for (i = 0; i < n; i++) {
      if (a[i] == 0) {
        c++;
        if (c == 2) break;
      }
    }
    if (c == 2)
      cout << "NO";
    else
      cout << "YES";
  }
}
