#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  float y, c;
  cin >> n;
  y = sqrt((8 * n) + 1) - 1;
  y = y / 2;
  c = y * 10;
  if (fmod(c, 10) == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
