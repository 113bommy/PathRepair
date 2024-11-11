#include <bits/stdc++.h>
using namespace std;
bool PLAY(long long x, long long y) {
  if (x > y) {
    long long t = x;
    x = y;
    y = t;
  }
  if (x == 0)
    return false;
  else if (PLAY(x, y % x) == false)
    return true;
  else
    return ((y / x) % (x + 1) == 0);
}
int main() {
  long long n, a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (PLAY(a, b) == true)
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
}
