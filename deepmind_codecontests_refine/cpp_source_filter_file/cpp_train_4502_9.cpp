#include <bits/stdc++.h>
using namespace std;
int main() {
  int nCases;
  cin >> nCases;
  for (int i = 0; i < nCases; i++) {
    long long nCandy = 0;
    cin >> nCandy;
    if (nCandy == 1 || nCandy == 2) {
      cout << 0 << endl;
    }
    if (nCandy % 2 == 0) {
      cout << (nCandy / 2) - 1 << endl;
    } else {
      cout << nCandy / 2 << endl;
    }
  }
  return 0;
}
