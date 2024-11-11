#include <bits/stdc++.h>
using namespace std;
string x;
int k1, k2;
int main() {
  int Y[21] = {2,  3,  4,  5,  7,  9,  11, 13, 17, 19, 23,
               25, 29, 31, 37, 41, 43, 47, 49, 59, 61};
  for (int i = 0; i <= 19; ++i) {
    cout << Y[i] << endl;
    fflush(stdout);
    cin >> x;
    if (x == "yes") {
      k1++;
    } else {
      k2++;
    }
  }
  if (k1 <= 1) {
    cout << "prime";
  } else {
    cout << "composite";
  }
  fflush(stdout);
  return 0;
}
