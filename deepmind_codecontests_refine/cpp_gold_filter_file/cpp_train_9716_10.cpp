#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  int acc[n], jus[n], accs = 0, juss = 0, count = 0;
  bool cc[n];
  for (int i = 0; i < n; ++i) {
    acc[i] = 0;
    jus[i] = 0;
    cc[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > 0) {
      acc[a[i] - 1]++;
      accs++;
    } else {
      jus[(-1 * a[i]) - 1]++;
      juss++;
    }
  }
  for (int i = 0; i < n; ++i) {
    int val = acc[i] + juss - jus[i];
    if (val == m) {
      cc[i] = 1;
      count += 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      if (cc[a[i] - 1] == 1) {
        if (count == 1) {
          cout << "Truth" << endl;
        } else {
          cout << "Not defined";
        }
      } else {
        cout << "Lie";
      }
    } else {
      a[i] *= -1;
      if (cc[a[i] - 1] == 1) {
        if (count == 1)
          cout << "Lie";
        else
          cout << "Not defined";
      } else {
        cout << "Truth";
      }
    }
    cout << endl;
  }
  return 0;
}
