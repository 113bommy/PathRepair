#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k;
  vector<int> v1, v2;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    v1.push_back(j);
  }
  int f = 0, a, b;
  for (i = 0; i < n; i++) {
    a = v1[i];
    for (j = i + 1; j < n; j++) {
      b = v1[j];
      for (k = j + 1; k < n; k++) {
        if (a + b == v1[k]) {
          f = 1;
          v2.push_back(i);
          v2.push_back(j);
          v2.push_back(k);
          break;
        }
      }
      if (f == 1) {
        break;
      }
    }
    if (f == 1) {
      break;
    }
  }
  if (f == 0) {
    cout << -1 << endl;
  } else if (f == 1) {
    cout << v2[2] + 1 << " " << v2[1] + 1 << " " << v2[0] + 1 << " " << endl;
  }
  return 0;
}
