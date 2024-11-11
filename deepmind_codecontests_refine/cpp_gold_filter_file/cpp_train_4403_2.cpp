#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int i;
  for (i = 0; i < n; i++) {
    cin >> m;
    int a[m];
    int j;
    for (j = 0; j < m; j++) {
      cin >> a[j];
    }
    int count = 0;
    for (j = 0; j < m; j++) {
      if (a[j] == 1) {
        count = count + 1;
      }
    }
    int x = 1;
    int steps = 0;
    int start = 0;
    for (j = 0; j < m; j++) {
      if (start > 0) {
        if (x < count) {
          if (a[j] == 0) {
            steps = steps + 1;
          }
          if (a[j] == 1) {
            x = x + 1;
          }
        }
      }
      if (a[j] == 1) {
        start = start + 1;
      }
    }
    cout << steps << endl;
  }
}
