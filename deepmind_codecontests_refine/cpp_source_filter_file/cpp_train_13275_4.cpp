#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  long long x;
  cin >> x;
  x = x % 360;
  if (x < 0) x += 360;
  if (x <= 45 || x >= 315) cout << 0;
  if (x > 45 && x <= 135)
    cout << 1;
  else if (x > 135 && x < 225)
    cout << 2;
  else if (x > 225 && x < 315)
    cout << 3;
  return 0;
}
