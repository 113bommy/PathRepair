#include <bits/stdc++.h>
using namespace std;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int m, d;
  cin >> m >> d;
  int dx = days[m - 1];
  int ans = 1;
  for (int i = 0; i < dx; i++) {
    if (d == 7) {
      d = 1;
      ans++;
    } else
      d++;
  }
  if (d == 1) ans--;
  cout << ans;
}
