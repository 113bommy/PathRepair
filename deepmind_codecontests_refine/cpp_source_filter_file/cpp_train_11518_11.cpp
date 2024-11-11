#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;
int a[MAXN], b[MAXN];
int c[3][8] = {{13, 14, 5, 6, 17, 18, 21, 22},
               {2, 4, 6, 8, 10, 12, 23, 21},
               {1, 2, 18, 20, 12, 1115, 13}};
bool check() {
  for (int i = 1; i <= 6; i++)
    for (int j = 1; j < 4; j++)
      if (b[i * 4] != b[i * 4 - j]) return 0;
  return 1;
}
int main() {
  for (int i = 1; i <= 24; i++) cin >> a[i];
  for (int j = 0; j < 3; j++) {
    for (int i = 1; i <= 24; i++) b[i] = a[i];
    for (int i = 0; i < 8; i++) b[c[j][(i + 2) % 8]] = a[c[j][i]];
    if (check()) {
      cout << "YES" << endl;
      return 0;
    }
    for (int i = 1; i <= 24; i++) b[i] = a[i];
    for (int i = 0; i < 8; i++) b[c[j][(i + 6) % 8]] = a[c[j][i]];
    if (check()) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
