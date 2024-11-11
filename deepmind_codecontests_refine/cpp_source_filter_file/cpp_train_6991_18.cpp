#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int a, b, c;
  cin >> a >> b >> c;
  if (a - b > c) {
    cout << "+" << endl;
  } else if (a - b < c && abs(a - b) != c && a - b != 0) {
    cout << "-" << endl;
  } else if (a - b == c && c == 0) {
    cout << 0 << endl;
  } else {
    cout << "?" << endl;
  }
}
