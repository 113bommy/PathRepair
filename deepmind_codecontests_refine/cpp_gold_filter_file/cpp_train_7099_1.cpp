#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  int u;
  while (q--) {
    int n;
    cin >> n;
    u = n;
    int res[u + 1];
    int p[n + 1];
    for (int i = 1; i <= n; i++) cin >> p[i];
    int day = 1;
    for (int i = 1; i <= n; i++) {
      bool found = true;
      int countt = 0;
      int j = i;
      while (found) {
        if (p[j] == i) {
          countt++;
          found = false;
        } else {
          j = p[j];
          countt++;
        }
      }
      res[i] = countt;
    }
    for (int i = 1; i <= u; i++) cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
