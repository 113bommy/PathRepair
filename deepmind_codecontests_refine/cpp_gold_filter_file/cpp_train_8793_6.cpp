#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
int d[3 * MAXN + 10], q[3 * MAXN + 10];
int main() {
  int n, m, h = 0, t = 0;
  cin >> n >> m;
  q[t++] = n;
  while (h < t) {
    int v = q[h++];
    if (v * 2 <= m * 2) {
      if (d[v] + 1 < d[v * 2] || d[v * 2] == 0) {
        d[v * 2] = d[v] + 1;
        q[t++] = v * 2;
      }
    }
    if (v - 1 >= 0) {
      if (d[v] + 1 < d[v - 1] || d[v - 1] == 0) {
        d[v - 1] = d[v] + 1;
        q[t++] = v - 1;
      }
    }
  }
  cout << d[m] << endl;
}
