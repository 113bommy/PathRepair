#include <bits/stdc++.h>
using namespace std;
int main() {
  int acc[] = {4, 8, 15, 16, 23, 42};
  int a[10];
  for (int m = 0; m < 4; m++) {
    cout << "? " << m << " " << m + 1 << endl;
    cin >> a[m];
    fflush(stdout);
  }
  do {
    int t = 1;
    for (int m = 0; m < 4; m++) {
      if (a[m] != acc[m] * acc[m + 1]) {
        t = 0;
      }
    }
    if (t) {
      break;
    }
  } while (next_permutation(acc, acc + 6));
  cout << "! ";
  for (int m = 0; m < 6; m++) {
    cout << acc[m] << " ";
  }
  fflush(stdout);
}
