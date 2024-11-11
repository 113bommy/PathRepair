#include <bits/stdc++.h>
using namespace std;
int findN(int l, int r) {
  int num, i, j;
  if (r == 1) return 0;
  num = 0;
  if (l <= r / 2) {
    l = r / 2 + 1;
  }
  num = r % l;
  return num;
}
int main() {
  int TC, l, r;
  cin >> TC;
  while (TC--) {
    cin >> l >> r;
    cout << findN(l, r) << endl;
  }
  return 0;
}
