#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  cin >> i >> j;
  if (j == 0) {
    cout << 1;
  } else if (j < i - 2) {
    cout << j;
  } else {
    cout << (i - j);
  }
}
