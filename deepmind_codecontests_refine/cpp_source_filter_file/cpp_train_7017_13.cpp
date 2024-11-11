#include <bits/stdc++.h>
using namespace std;
void domain_expansion_() {
  int n, m;
  cin >> n >> m;
  int a[n];
  int x, y, z;
  memset(a, -1, sizeof(a));
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    if (a[x - 1] != -1) {
      if (a[x - 1] == 1) {
        a[y - 1] = 2;
        a[z - 1] = 3;
      }
      if (a[x - 1] == 2) {
        a[y - 1] = 3;
        a[z - 1] = 1;
      }
      if (a[x - 1] == 3) {
        a[y - 1] = 1;
        a[z - 1] = 2;
      }
    } else if (a[y - 1] != -1) {
      if (a[y - 1] == 1) {
        a[x - 1] = 2;
        a[z - 1] = 3;
      }
      if (a[y - 1] == 2) {
        a[x - 1] = 3;
        a[z - 1] = 1;
      }
      if (a[y - 1] == 3) {
        a[x - 1] = 1;
        a[z - 1] = 2;
      }
    } else if (a[z - 1] != -1) {
      if (a[z - 1] == 1) {
        a[y - 1] = 2;
        a[z - 1] = 3;
      }
      if (a[z - 1] == 2) {
        a[y - 1] = 3;
        a[z - 1] = 1;
      }
      if (a[z - 1] == 3) {
        a[y - 1] = 1;
        a[x - 1] = 2;
      }
    } else {
      a[x - 1] = 1;
      a[y - 1] = 2;
      a[z - 1] = 3;
    }
  }
  for (int x : a) cout << x << " ";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) domain_expansion_();
  return 0;
}
