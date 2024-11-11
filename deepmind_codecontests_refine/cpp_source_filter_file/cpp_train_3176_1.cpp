#include <bits/stdc++.h>
using namespace std;
int main() {
  int kronk, izma;
  int Bad_lama;
  cin >> izma >> kronk;
  if (kronk == 10)
    Bad_lama = 2;
  else
    Bad_lama = 1;
  if (Bad_lama == 2 and izma == 1) {
    cout << -1;
    return 0;
  }
  if (Bad_lama == 1) {
    while (izma != 0) {
      cout << kronk;
      izma--;
    }
  } else {
    izma--;
    cout << kronk;
    while (izma != 0) {
      cout << 0;
      izma--;
    }
  }
}
