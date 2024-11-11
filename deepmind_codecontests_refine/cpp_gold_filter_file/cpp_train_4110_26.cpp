#include <bits/stdc++.h>
using namespace std;
int MAIN() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int misha = max(3 * a / 10, a - a / 250 * c);
  int vasya = max(3 * b / 10, b - b / 250 * d);
  if (vasya > misha) {
    cout << "Vasya" << endl;
  } else if (misha > vasya) {
    cout << "Misha" << endl;
  } else {
    cout << "Tie" << endl;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  int ret = MAIN();
  return ret;
}
