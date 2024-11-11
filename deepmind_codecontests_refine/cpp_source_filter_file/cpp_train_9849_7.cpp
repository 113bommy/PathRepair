#include <bits/stdc++.h>
using namespace std;
int n, k, dem, m, b[100001], a[200001][2];
int main() {
  cin >> n >> k;
  for (register int i = (2); i <= (min(1 + k, n)); ++i) {
    ++dem;
    a[dem][0] = 1;
    a[dem][1] = i;
    int u = i, v = i + k, h = 0;
    while (v <= n) {
      ++h;
      ++dem;
      a[dem][0] = u;
      a[dem][1] = v;
      u = v;
      v += k;
    }
    ++m;
    b[m] = h;
  }
  sort(b + 1, b + 1 + m);
  cout << b[m] + b[m - 1] + 2 << endl;
  for (register int i = (1); i <= (dem); ++i)
    cout << a[i][0] << ' ' << a[i][1] << endl;
}
