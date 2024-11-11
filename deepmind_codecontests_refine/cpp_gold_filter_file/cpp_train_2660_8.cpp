#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  for (int i = 0; i < 3; i++) {
    int min = i;
    for (int j = i + 1; j < 4; j++) {
      if (a[j] > a[min]) min = j;
    }
    if (min != i) {
      int temp;
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }
  }
  if (a[3] + a[2] > a[0] || a[3] + a[1] > a[0] || a[1] + a[2] > a[0] ||
      a[3] + a[2] > a[1]) {
    cout << "TRIANGLE" << endl;
  } else {
    if (a[3] + a[2] == a[0] || a[3] + a[1] == a[0] || a[1] + a[2] == a[0] ||
        a[3] + a[2] == a[1]) {
      cout << "SEGMENT" << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}
