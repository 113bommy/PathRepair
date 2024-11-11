#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, out, max;
  int boy[360];
  int girl[360];
  char g[5000];
  int f[5000];
  int e[5000];
  while (cin >> n) {
    boy[360] = 0;
    girl[360] = 0;
    out = 0;
    max = 0;
    for (int i = 0; i < n; i++) {
      cin >> g[i] >> f[i] >> e[i];
      for (int d = f[i]; d <= e[i]; d++) {
        if (g[i] == 'M')
          boy[d]++;
        else
          girl[d]++;
      }
    }
    for (int i = 1; i <= 366; i++) {
      out = min(girl[i], boy[i]);
      if (out > max) max = out;
    }
    cout << max * 2 << endl;
  }
  return 0;
}
