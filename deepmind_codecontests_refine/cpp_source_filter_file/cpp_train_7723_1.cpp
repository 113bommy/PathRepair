#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int a[k][1001];
  int p;
  for (int i = 0; i < k; i++) {
    cin >> a[i][0];
    for (int j = 1; j <= a[i][0]; j++) {
      a[i][j] = 0;
    }
    for (int j = 0; j < a[i][0]; j++) {
      cin >> p;
      a[i][p] += p;
    }
  }
  int s, t;
  int d;
  for (int i = 0; i < k; i++) {
    s = a[i][0];
    t = 0;
    while (t <= s) {
      if (a[i][s] == 0) {
        s--;
        d = 1;
      } else {
        a[i][s] -= s;
        t++;
        d = 0;
      }
    }
    if (d == 1) {
      cout << t;
    }
    if (d == 0) {
      cout << t - 1 << endl;
    }
  }
}
