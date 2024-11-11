#include <bits/stdc++.h>
using namespace std;
map<int, int> ile;
int a[1007], p[1007];
int x, y, n, s, out, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ile[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        x = a[i];
        y = a[j];
        p[0] = x;
        p[1] = y;
        ile[x]--;
        ile[y]--;
        s = 2;
        if (x == 0 && y == 0) {
          out = max(out, ile[0]);
        } else {
          while (true) {
            if (ile[x + y] > 0) {
              ile[x + y]--;
              p[s] = x + y;
              s++;
              r = x;
              x = y;
              y = x + r;
            } else {
              break;
            }
          }
          out = max(out, s);
        }
        for (int q = 0; q < s; q++) {
          ile[p[q]]++;
        }
      }
    }
  }
  cout << out;
}
