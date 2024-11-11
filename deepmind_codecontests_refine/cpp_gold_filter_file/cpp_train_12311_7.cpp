#include <bits/stdc++.h>
using namespace std;
void puzzle() {
  double a, b, c;
  cin >> a >> b >> c;
  if (a < (c / b) || (b > 1 && c > a)) {
    cout << 1 << " ";
  } else {
    cout << -1 << " ";
  }
  if ((a * b > c)) {
    cout << (int)b << " ";
  } else {
    cout << -1 << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    puzzle();
  }
}
