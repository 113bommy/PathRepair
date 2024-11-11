#include <bits/stdc++.h>
using namespace std;
int main() {
  char a, b, c[5], d[5];
  bool e = false;
  cin >> a >> b;
  for (int i = 0; i < 5; i++) {
    cin >> c[i] >> d[i];
    if (c[i] == a || d[i] == b) {
      e = true;
      break;
    }
  }
  if (e == true) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
