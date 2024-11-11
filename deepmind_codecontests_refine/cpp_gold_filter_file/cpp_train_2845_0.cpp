#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 321;
const int maxN = 1000 * 100 + 321;
const int maxX = 1000 * 1000 * 10 + 5;
int mark[maxN];
int b[maxN];
int k[maxN];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  k[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (k[i] == 0) {
      k[i] = i;
      for (int j = i + i; j <= n; j += i) k[j] = i;
    }
  }
  while (m--) {
    char c;
    int r;
    cin >> c >> r;
    if (c == '+') {
      if (mark[r]) {
        cout << "Already on" << endl;
        continue;
      }
      int t = r;
      for (int i = k[t]; i > 1; i = k[t]) {
        if (b[i]) {
          cout << "Conflict with " << b[i] << endl;
          t = 0;
          break;
        }
        while (!(t % i)) t /= i;
      }
      if (t) {
        mark[r] = 1;
        t = r;
        cout << "Success" << endl;
        for (int i = k[t]; i > 1; i = k[t])
          while (!(t % i)) {
            b[i] = r;
            t /= i;
          }
      }
    } else {
      if (!mark[r]) {
        cout << "Already off" << endl;
        continue;
      }
      mark[r] = 0;
      cout << "Success" << endl;
      for (int i = k[r]; i > 1; i = k[r]) {
        while (!(r % i)) {
          b[i] = 0;
          r /= i;
        }
      }
    }
  }
  return 0;
}
