#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if ((b - a) * c < 0 && b != a) {
    cout << "NO";
    return 0;
  } else {
    if (c == 0) {
      cout << (b == a ? "YES" : "NO");
      return 0;
    }
    if ((b - a) % c == 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
