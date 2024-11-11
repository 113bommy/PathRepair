#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c % a == 0 || c % b == 0) {
    cout << "Yes";
    return 0;
  }
  for (int i = 0; i <= c; i++) {
    for (int j = 0; j <= c; j++) {
      if ((i * a) + (j * b) == c) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
