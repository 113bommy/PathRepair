#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  int sum = 0;
  cin >> t;
  while (t[0] != t[4] || t[1] != t[3]) {
    t[4] += 1;
    sum++;
    if (t[4] > '9') {
      t[4] = '0';
      t[3] += 1;
    }
    if (t[3] > '5') {
      t[3] = '0';
      t[1] += 1;
    }
    if (t[1] > '9') {
      t[1] = '0';
      t[0] += 1;
    }
    if (t[0] > '1' && t[1] > '3') {
      t[0] = '0';
      t[1] = '0';
    }
  }
  cout << sum;
  return 0;
}
