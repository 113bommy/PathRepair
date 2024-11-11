#include <bits/stdc++.h>
using namespace std;
int vis[100010];
double a[100010];
int main() {
  int n;
  while (cin >> n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      int shang = ceil(a[i]);
      int xia = floor(a[i]);
      if (shang == xia) vis[i] = 1;
    }
    double cha = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i] != 1) {
        double shang = fabs(ceil(a[i]) - a[i]);
        double xia = fabs(floor(a[i]) - a[i]);
        if (cha + shang < 0.5) {
          vis[i] = 2;
          cha += shang;
        } else {
          vis[i] = -1;
          cha -= xia;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (vis[i] == -1) {
        cout << int(floor(a[i])) << endl;
      }
      if (vis[i] == 1) {
        cout << int(a[i]) << endl;
      }
      if (vis[i] == 2) {
        cout << int(ceil(a[i])) << endl;
      }
    }
  }
  return 0;
}
