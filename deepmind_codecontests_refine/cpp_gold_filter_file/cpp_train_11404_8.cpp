#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int br = 0;
  double a[n + 10][n + 10];
  memset(a, 0, sizeof(a));
  int pomm = 2;
  int pom1 = 0;
  if (k == 0) {
    cout << 0 << endl;
    return 0;
  }
  a[0][0] = 10;
  int br1 = 0;
  for (int i = 1; i < k; i++) {
    pom1 = 0;
    pomm = 1;
    a[0][0] += 10;
    while (1 == 1) {
      if (pom1 == 10) break;
      bool f = false;
      for (int pom = 0; pom < pomm; pom++) {
        if (a[pom1][pom] > 10) {
          a[pom1 + 1][pom] += (a[pom1][pom] - 10) / 2;
          a[pom1 + 1][pom + 1] += (a[pom1][pom] - 10) / 2;
          a[pom1][pom] = 10;
          f = true;
        }
      }
      pomm++;
      pom1++;
      if (!f) break;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i + 1; j++) {
        if (a[i][j] == 10) {
          br1++;
        }
      }
    }
    if (br1 == (n * (n + 1)) / 2) {
      cout << (n * (n + 1)) / 2 << endl;
      return 0;
    }
    br1 = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (a[i][j] == 10) {
        br++;
      }
    }
  }
  cout << br << endl;
  return 0;
}
