#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int d[n][2];
  int a = 0, b = 0, t1, t2;
  for (int i = 0; i < n; i++) {
    cin >> d[i][0];
    if (d[i][0] == 1) {
      a++;
    }
    cin >> d[i][1];
    if (d[i][1] == 1) {
      b++;
    }
  }
  if (a == n || a == 0) {
    t1 = 0;
  } else {
    if (a <= (n / 2)) {
      t1 = a;
    } else {
      t1 = n - a;
    }
  }
  if (b == n || b == 0) {
    t1 = 0;
  } else {
    if (b <= (n / 2)) {
      t2 = b;
    } else {
      t2 = n - b;
    }
  }
  cout << t1 + t2;
  return 0;
}
