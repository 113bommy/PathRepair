#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, w;
  cin >> y >> w;
  int m = max(y, w);
  int n = 6 - m;
  if (n == 0) {
    cout << "0/1";
  } else if (n == 1) {
    cout << "1/6";
  } else if (n == 2) {
    cout << "1/3";
  } else if (n == 3) {
    cout << "1/2";
  } else if (n == 4) {
    cout << "2/3";
  } else if (n == 5) {
    cout << "5/6";
  } else if (n == 6) {
    cout << "1/1";
  }
  return 0;
}
