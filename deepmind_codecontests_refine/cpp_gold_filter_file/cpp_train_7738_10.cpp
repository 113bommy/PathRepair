#include <bits/stdc++.h>
using namespace std;
int prim[100000];
int main() {
  int a, b;
  cin >> a >> b;
  bool ok = false;
  int x = 0;
  for (int i = 3; i <= a; i++) {
    for (int j = 2; j < i / 2; j++) {
      if (i % j == 0) {
        ok = true;
        break;
      }
    }
    if (ok == false) {
      prim[x] = i;
      x++;
    }
    ok = false;
  }
  int sum = 0;
  int xx = 0;
  for (int i = 0; i < x; i++) {
    sum = prim[i] + prim[i + 1] + 1;
    for (int j = 0; j < x; j++) {
      if (sum == prim[j]) {
        xx++;
        break;
      }
    }
  }
  if (xx >= b) {
    cout << "YES";
    return 0;
  } else {
    cout << "NO";
    return 0;
  }
}
