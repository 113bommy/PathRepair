#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(7);
  if (a > 0) {
    cout << (-1 * b + sqrt(b * b - 4 * a * c)) / 2 * a << endl;
    cout << (-1 * b - sqrt(b * b - 4 * a * c)) / 2 * a << endl;
  } else {
    cout << (-1 * b - sqrt(b * b - 4 * a * c)) / 2 * a << endl;
    cout << (-1 * b + sqrt(b * b - 4 * a * c)) / 2 * a << endl;
  }
}
