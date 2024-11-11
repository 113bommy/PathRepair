#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, i, j, x[105], mini, maks, y[505];
  string temp;
  map<string, int> z;
  cin >> a >> b;
  for (i = 0; i < a; i++) {
    cin >> x[i];
  }
  c = 0;
  for (i = 1; i <= b; i++) {
    cin >> temp;
    if (z[temp] == 0) {
      c++;
      y[c] = 1;
      z[temp] = 1;
    } else {
      y[z[temp]]++;
    }
  }
  sort(x, x + a);
  sort(y + 1, y + c + 1);
  d = c;
  mini = 0;
  maks = 0;
  for (i = 1; i <= c; i++) {
    d--;
    mini += x[d] * y[i];
  }
  d = a;
  for (i = c; i >= 1; i--) {
    d--;
    maks += y[i] * x[d];
  }
  cout << mini << " " << maks << "\n";
}
