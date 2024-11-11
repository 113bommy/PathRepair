#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans1 = max(a * 3 / 10, a - (a / 250) * c);
  int ans2 = max(b * 3 / 10, b - (b / 250) * d);
  if (ans1 > ans2) {
    cout << "misha" << endl;
  } else if (ans1 < ans2) {
    cout << "vasya" << endl;
  } else {
    cout << "tie" << endl;
  }
}
