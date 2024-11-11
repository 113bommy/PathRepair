#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int num1 = min(b, c / 2);
    b -= num1;
    int num2 = min(a, b / 2);
    cout << (num1 + num2) * 2 << endl;
  }
  return 0;
}
