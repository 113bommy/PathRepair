#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int n;
void out() {
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) cout << a[i][k] << " ";
    cout << endl;
  }
}
int main() {
  int k;
  cin >> n >> k;
  if (k > n * n) {
    cout << -1;
    return 0;
  }
  int num = 0;
  for (int j = 0; j < n; j++) {
    for (int z = 0; z < n; z++) {
      if (a[j][z] == 0 && (k - num) >= 1) {
        if (j == z) {
          a[j][z] = 1;
          num++;
        } else if ((k - num) >= 2) {
          a[j][z] = 1;
          a[z][j] = 1;
          num += 2;
        }
        if (num == k) {
          out();
          return 0;
        }
      }
      if (num == k) {
        out();
        return 0;
      }
    }
  }
  out();
}
