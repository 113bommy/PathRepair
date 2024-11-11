#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[10000], x[5], z1[10000], z2[10000], z3[10000], a = 0, b = 0, c = 0;
  x[0] = {0}, x[1] = {0}, x[2] = {0};
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1) {
      x[0] += 1;
      z1[a] = i;
      a++;
    } else if (arr[i] == 2) {
      x[1] += 1;
      z2[b] = i;
      b++;
    } else if (arr[i] == 3) {
      x[2] += 1;
      z3[c] = i;
      c++;
    }
  }
  if (x[0] == 0 || x[1] == 0 || x[2] == 0) {
    cout << "0" << endl;
    goto m;
  }
  sort(x, x + 3);
  cout << x[0] << endl;
  for (int i = 0; i < x[0]; i++) {
    cout << z1[i] << " " << z2[i] << " " << z3[i] << endl;
  }
m:
  return 0;
}
