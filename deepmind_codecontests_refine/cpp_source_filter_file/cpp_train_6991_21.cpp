#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b + c) {
    cout << "+" << endl;
  } else if (b > a + c) {
    cout << "-" << endl;
  } else if (a == b && c == 0) {
    cout << "-" << endl;
  } else
    cout << "?" << endl;
}
