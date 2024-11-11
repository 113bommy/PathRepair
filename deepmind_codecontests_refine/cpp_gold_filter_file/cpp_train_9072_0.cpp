#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  if (n % 2 == 0) {
    m = n / 2 + 1;
  } else {
    m = (n - 1) / 2 + 1;
  }
  cout << m << endl;
  int x = 1, y = 1;
  for (int i = 0; i < n; i++) {
    cout << x << " " << y << endl;
    if (i % 2 == 0) {
      x++;
    } else {
      y++;
    }
  }
  return 0;
}
