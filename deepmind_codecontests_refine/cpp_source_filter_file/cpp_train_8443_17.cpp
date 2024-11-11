#include <bits/stdc++.h>
using namespace std;
int n;
int a[2000][2000];
bool u[2000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
  }
  for (int i = 0; i < n; i++) {
    bool fl = 1;
    for (int j = 0; j < n; j++)
      if (i != j) {
        fl = 0;
        for (int k = 0; k < 3; k++)
          if (a[i][k] > a[j][k]) {
            fl = 1;
            break;
          }
        if (!fl) break;
      }
    if (!fl) {
      u[i] = 1;
    }
  }
  int mn = -1;
  for (int i = 0; i < n; i++)
    if (!u[i] && (mn == -1 || a[i][3] < a[mn][3])) mn = i;
  cout << mn + 1;
  return 0;
}
