#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[10];
  for (int i = 1; i < 7; i++) {
    if ((n - 4 * i) % 7 == 0 && (n - 4 * i) >= 0) {
      for (int j = 0; j < i; j++) cout << 4;
      n = n - 4 * i;
      for (int j = 0; j < n / 7; j++) cout << 7;
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
