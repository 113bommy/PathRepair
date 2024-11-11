#include <bits/stdc++.h>
using namespace std;
void maloosh_lazma() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  maloosh_lazma();
  int a, b, c, d, tot, tot2;
  cin >> a >> b >> c >> d;
  tot = max((3 * a) / 10, a - (a / 250) * c);
  tot2 = max((3 * a) / 10, b - (b / 250) * d);
  if (tot > tot2) {
    cout << "Misha";
  } else if (tot2 > tot) {
    cout << "Vasya";
  } else {
    cout << "Tie";
  }
  return 0;
}
