#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c == 0) {
    if (a == b)
      cout << "YES";
    else
      cout << "NO";
    return 0;
  }
  if (c > 0 && b < a) {
    cout << "NO";
    return 0;
  }
  if (c < 0 && b > a) {
    cout << "NO";
    return 0;
  }
  if ((b - a) % c != 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
