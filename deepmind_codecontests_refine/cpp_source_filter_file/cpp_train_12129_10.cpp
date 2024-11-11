#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n], sa = 0, sb = 0, temp;
  a[0] = 0, b[0] = 0;
  for (int i = 1; i < n; i++) {
    cin >> temp;
    sa = sa + temp;
    a[i] = sa;
  }
  for (int i = 1; i < n; i++) {
    cin >> temp;
    sb = sb + temp;
    b[i] = sb;
  }
  int c[n + 1];
  for (int i = 1; i <= n; i++) cin >> c[i];
  int path[n + 1];
  int cp = 1, s = 100000, ss = 100000, j;
  for (int i = n; i >= 1; i--) {
    path[cp] = c[i] + a[i - 1] + (sb - b[i - 1]);
    if (path[cp] < s) {
      s = path[cp];
      j = i;
    }
    cp++;
  }
  for (int i = 1; i < cp; i++) {
    if (j == i)
      continue;
    else {
      if (ss > path[i]) ss = path[i];
    }
  }
  cout << s + ss << endl;
}
