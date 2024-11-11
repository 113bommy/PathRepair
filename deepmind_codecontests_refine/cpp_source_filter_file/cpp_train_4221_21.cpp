#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, cnt = 0, s = 0;
  cin >> x;
  while (x) {
    s = x / 8;
    x /= 8;
    if (s == 1) cnt++;
  }
  cout << cnt;
}
