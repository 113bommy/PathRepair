#include <bits/stdc++.h>
using namespace std;
int abs(int x, int y) {
  if (x - y >= 0)
    return (x - y);
  else
    return (y - x);
}
int main() {
  long int x, y = 0, cnt = 0, n;
  cin >> n;
  while (n--) {
    cin >> x;
    cnt = cnt + abs(x, y);
    y = x;
  }
  cout << cnt;
  return 0;
}
