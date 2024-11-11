#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0, y = 0;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < b.size(); i++) {
    if (b[x] == a[y]) {
      x++;
      y++;
    } else {
      x++;
    }
  }
  cout << (y + 1);
}
