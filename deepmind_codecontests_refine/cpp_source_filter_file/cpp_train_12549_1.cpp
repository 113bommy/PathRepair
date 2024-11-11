#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0, a;
  cin >> n;
  if (n > 1) {
    for (int i = 0; i < n; i++) {
      cin >> a;
      x = x + a;
    }
    if (x == (n - 1))
      cout << "YES";
    else
      cout << "NO";
  } else {
    cin >> a;
    if (a = 1)
      cout << "YES";
    else
      cout << "NO";
  }
}
