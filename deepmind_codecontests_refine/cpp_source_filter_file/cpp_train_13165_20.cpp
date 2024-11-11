#include <bits/stdc++.h>
using namespace std;
int main() {
  string num;
  int c[10] = {2, 7, 2, 3, 3, 3, 2, 5, 1, 2};
  while (cin >> num) {
    cout << c[num[0] - '0'] * c[num[1] - '0'] << endl;
  }
  return 0;
}
