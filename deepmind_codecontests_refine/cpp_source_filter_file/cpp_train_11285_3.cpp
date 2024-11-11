#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65777216")
const int INF = 2000000000;
const double PI = 3.14159265358979323846;
using namespace std;
int main() {
  int n, c;
  int a[100000];
  vector<int> z[33];
  cin >> n;
  for (int i(0); i < n; i++) {
    cin >> a[i];
    if (a[i] != 0) {
      int k = 0;
      int t = a[i];
      while (t != 0) {
        t = t >> 1;
        if (t & 1 == 1) {
          z[k].push_back(a[i]);
        }
        k++;
      }
    }
  }
  for (int i(32); i >= 0; i--) {
    int l = z[i].size();
    if (l != 0) {
      c = z[i][0];
      for (int j(1); j < l; j++) {
        c = c & z[i][j];
      }
      if (c % (1 << i) == 0) {
        cout << l << endl;
        for (int j(0); j < l; j++) {
          cout << z[i][j] << ' ';
        }
        return 0;
      }
    }
  }
}
