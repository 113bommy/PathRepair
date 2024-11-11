#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c % a == 0) {
    cout << "YES";
    return 0;
  }
  if (c % b == 0) {
    cout << "YES";
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= c / a; i++) {
    ans = a * i;
    if ((c - ans) % b == 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
