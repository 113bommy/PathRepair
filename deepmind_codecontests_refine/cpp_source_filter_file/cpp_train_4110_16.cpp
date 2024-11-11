#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int a, b, c, d;
  cin >> a >> b >> c >> d;
  long long int m = max(((3 * a) / 10), (a - (a / 250)) * c);
  long long int v = max(((3 * b) / 10), (b - (b / 250)) * d);
  if (m == v) {
    cout << "Tie" << endl;
  } else if (m > v) {
    cout << "Misha" << endl;
  } else {
    cout << "Vasya" << endl;
  }
  return 0;
}
