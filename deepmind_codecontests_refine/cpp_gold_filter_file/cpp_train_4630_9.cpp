#include <bits/stdc++.h>
using namespace std;
const int mx = 5e3 + 53;
int n, a[mx], b[3][mx], sh;
bool mark[3][mx], mark1[mx];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1 && mark[0][sh] != true && mark1[i] != true) {
      b[0][sh] = i + 1;
      mark[0][sh] = true;
      mark1[i] = true;
    }
    if (a[i] == 2 && mark[1][sh] != true && mark1[i] != true) {
      b[1][sh] = i + 1;
      mark[1][sh] = true;
      mark1[i] = true;
    }
    if (a[i] == 3 && mark[2][sh] != true && mark1[i] != true) {
      b[2][sh] = i + 1;
      mark[2][sh] = true;
      mark1[i] = true;
    }
    if (mark[0][sh] == true && mark[1][sh] == true && mark[2][sh] == true) {
      sh++;
      i = 0;
    }
  }
  cout << sh << endl;
  for (int i = 0; i < sh; i++) {
    for (int j = 0; j < 3; j++) {
      cout << b[j][i] << " ";
    }
    cout << endl;
  }
}
