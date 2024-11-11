#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int s, f, t;
    cin >> s >> f >> t;
    if (s == f) {
      cout << "0\n";
      continue;
    }
    int curr = t % (2 * (m - 1));
    bool up;
    if (curr <= m - 1) {
      up = 1;
      curr = curr + 1;
    } else {
      up = 0;
      curr = m - (curr - m + 1);
    }
    int t1;
    if (curr == s)
      t1 = t;
    else if (curr < s) {
      if (up) {
        t1 = t + s - curr;
        if (s == m) up = 0;
      } else {
        t1 = t + curr - 1 + s - 1;
        if (s == m)
          up = 0;
        else
          up = 1;
      }
    } else {
      if (!up) {
        t1 = t + curr - s;
        if (s == 1) up = 1;
      } else {
        t1 = t + m - curr + m - s;
        if (s == 1)
          up = 1;
        else
          up = 0;
      }
    }
    if (s < f) {
      if (up)
        t1 += f - s;
      else {
        t1 += s - 1 + f - 1;
      }
    } else {
      if (!up)
        t1 += s - f;
      else {
        t1 += m - s + m - f;
      }
    }
    cout << t1 << "\n";
  }
  return 0;
}
