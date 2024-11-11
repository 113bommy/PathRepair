#include <bits/stdc++.h>
using namespace std;

int main() {
  long x;
  cin >> x;
  x--;
  long ans = x / 11 * 2;
  ans += 5 < x % 11;
  cout << ans + 1 << endl;
}