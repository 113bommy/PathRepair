#include <bits/stdc++.h>
using namespace std;
int main() {
  long a, b, pos, k;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> k;
    if (k % 2 == 0)
      pos = (k / 2) * a - (k / 2) * b;
    else
      pos = ((k + 1) / 2) * a - (k / 2) * b;
    cout << pos << endl;
  }
  return 0;
}
