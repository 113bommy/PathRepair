#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int p[n], f[m];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> f[i];
  }
  sort(p, p + n);
  sort(f, f + m);
  int t = p[n - 1];
  while (t < f[0]) {
    if (p[0] <= t / 2)
      break;
    else
      t++;
  }
  if (t >= f[0])
    cout << "-1" << endl;
  else
    cout << t << endl;
  return 0;
}
