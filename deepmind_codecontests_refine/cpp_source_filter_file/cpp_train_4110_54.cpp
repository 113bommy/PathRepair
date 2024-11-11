#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, ans1, ans2;
  cin >> a >> b >> c >> d;
  ans1 = max(3 * a / 100, a - (a / 250 * c));
  ans2 = max(3 * b / 100, b - (b / 250 * d));
  if (ans1 > ans2) {
    cout << "Misha\n";
  } else if (ans2 > ans1) {
    cout << "Vasya\n";
  } else
    cout << "Tie\n";
  return 0;
}
