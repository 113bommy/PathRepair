#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << n / 2 + 1 << endl;
  int x = 1;
  int y = 1;
  int i = 0;
  while (x <= n / 2 + 1 && i < n) {
    cout << x << " 1" << endl;
    x++;
    i++;
  }
  while (y <= n / 2 + 1 && i < n) {
    y++;
    cout << n / 2 + 1 << " " << y << endl;
    i++;
  }
}
