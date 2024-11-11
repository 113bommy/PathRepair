#include <bits/stdc++.h>
using namespace std;
long long inf = 998244353;
vector<string> a;
int f(int i12, int j12) {
  int i1, j1;
  i1 = i12;
  j1 = j12;
  int k = 0;
  if (j1 >= 1)
    while (a[i1][j1 - 1] == 'X') {
      k++;
      j1++;
      if (j1 < 1) break;
    }
  i1 = i12;
  j1 = j12;
  if (j1 <= 8)
    while (a[i1][j1 + 1] == 'X') {
      k++;
      j1++;
      if (j1 >= 9) break;
    }
  i1 = i12;
  j1 = j12;
  if (k >= 4) return 1;
  i1 = i12;
  j1 = j12;
  k = 0;
  if (i1 >= 1)
    while (a[i1 - 1][j1] == 'X') {
      k++;
      i1++;
      if (i1 < 1) break;
    }
  i1 = i12;
  j1 = j12;
  if (i1 <= 8)
    while (a[i1 + 1][j1] == 'X') {
      k++;
      i1++;
      if (i1 >= 9) break;
    }
  if (k >= 4) return 1;
  i1 = i12;
  j1 = j12;
  k = 0;
  if (i1 >= 1 && j1 >= 1)
    while (a[i1 - 1][j1 - 1] == 'X') {
      k++;
      i1--;
      j1--;
      if (i1 < 1 || j1 < 1) break;
    }
  i1 = i12;
  j1 = j12;
  if (i1 <= 8 && j1 <= 8)
    while (a[i1 + 1][j1 + 1] == 'X') {
      k++;
      i1++;
      j1++;
      if (i1 > 8 || j1 > 8) break;
    }
  if (k >= 4) return 1;
  k = 0;
  i1 = i12;
  j1 = j12;
  if (i1 >= 1 && j1 <= 8)
    while (a[i1 - 1][j1 + 1] == 'X') {
      k++;
      i1--;
      j1++;
      if (i1 < 1 || j1 > 8) break;
    }
  i1 = i12;
  j1 = j12;
  if (i1 <= 8 && j1 >= 1)
    while (a[i1 + 1][j1 - 1] == 'X') {
      k++;
      i1++;
      j1--;
      if (j1 < 1 || i1 > 8) break;
    }
  if (k >= 4) return 1;
  return 0;
}
int main() {
  int n = 10;
  a.assign(n, "");
  for (int i = 0; i < n; i++) cin >> a[i];
  int k = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10; j++) {
      if (a[i][j] != 'O') {
        int res = f(i, j);
        if (res == 1) {
          cout << "YES";
          return 0;
        }
      }
    }
  cout << "NO";
  return 0;
}
