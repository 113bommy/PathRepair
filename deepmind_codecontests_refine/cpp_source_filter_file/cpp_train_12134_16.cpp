#include <bits/stdc++.h>
using namespace std;
int t = 1, raodenoba, i, k;
int main() {
  cin >> raodenoba;
  if (raodenoba == 1) {
    cout << "1";
    return 0;
  }
  int a[raodenoba];
  for (i = 0; i < raodenoba; i++) {
    cin >> a[i];
  }
  for (i = 1; i < raodenoba; i++) {
    if (a[i] > a[i - 1]) {
      t++;
      if (t > k) k = t;
    } else
      t = 1;
  }
  cout << k;
}
