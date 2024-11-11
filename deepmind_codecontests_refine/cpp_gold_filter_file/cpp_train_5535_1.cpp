#include <bits/stdc++.h>
using namespace std;
long long INF = 1000 * 1000 * 1000;
long long p = 31;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int s, f, t;
    cin >> s >> f >> t;
    s--;
    f--;
    int step = t / (m - 1);
    if (s == f) {
      cout << t << endl;
      continue;
    }
    if (s < f) {
      if (step % 2 == 1) step++;
      if (step * (m - 1) + s >= t)
        cout << step * (m - 1) + f << endl;
      else
        cout << (step + 2) * (m - 1) + f << endl;
    } else {
      if (step % 2 == 0) step++;
      if (step * (m - 1) + m - s - 1 >= t)
        cout << step * (m - 1) + m - f - 1 << endl;
      else
        cout << (step + 2) * (m - 1) + m - f - 1 << endl;
    }
  }
  return 0;
}
