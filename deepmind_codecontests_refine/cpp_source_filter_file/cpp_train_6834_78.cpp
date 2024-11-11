#include <bits/stdc++.h>
using namespace std;
int n;
int i, j;
int main() {
  cin >> n;
  if (n >= 37) {
    cout << -1 << endl;
    return 0;
  } else {
    if (n % 2 == 0) {
      for (i = 1; i <= n / 2; i++) cout << 8;
      cout << endl;
      return 0;
    } else {
      for (i = 1; i <= n / 2; i++) cout << 8;
      cout << 0 << endl;
      return 0;
    }
  }
}
