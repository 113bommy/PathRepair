#include <bits/stdc++.h>
using namespace std;
int main() {
  int n[1005], i, k, l, j, z;
  for (i = 0; i < l; i++) {
    n[i] = 0;
  }
  cin >> l;
  for (i = 0; i < l; i++) {
    cin >> n[i];
  }
  for (i = 1; i < l; i++) {
    if (i % 2)
      n[i] += n[0];
    else
      n[i] -= n[0];
    if (n[i] >= l)
      n[i] -= l;
    else if (n[i] < 0)
      n[i] += l;
  }
  n[0] = 0;
  z = 0;
  for (i = 0; i < l - 1; i++) {
    if (n[i] != i) {
      z++;
      break;
    }
  }
  if (z)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
