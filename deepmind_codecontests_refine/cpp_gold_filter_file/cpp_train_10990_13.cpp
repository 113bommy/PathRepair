#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, d, i;
  int days;
  cin >> m >> d;
  int mn = 4;
  if (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12)
    days = 31;
  else if (m == 2)
    days = 28;
  else
    days = 30;
  days -= 28;
  i = 7 - d + 1;
  if (days <= 0 and i == 7) {
    cout << mn;
    return 0;
  }
  days -= i;
  mn++;
  if (days <= 0) {
    cout << mn;
    return 0;
  }
  cout << mn + 1;
  return 0;
}
