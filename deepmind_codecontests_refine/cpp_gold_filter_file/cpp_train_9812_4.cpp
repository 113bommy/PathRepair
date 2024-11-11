#include <bits/stdc++.h>
using namespace std;
long long x[10], y[10];
long long sqr(long long x) { return x * x; }
long long dist(int i, int j) { return sqr(x[i] - x[j]) + sqr(y[i] - y[j]); }
long long ang(int i, int j, int k) {
  long long x1 = x[j] - x[i], x2 = x[k] - x[i];
  long long y1 = y[j] - y[i], y2 = y[k] - y[i];
  return x1 * x2 + y1 * y2;
}
int main() {
  int n = 8;
  for (int i = (0); i < ((int)(n)); i++) {
    cin >> x[i] >> y[i];
  }
  int p[10];
  for (int i = (0); i < ((int)(n)); i++) {
    p[i] = i;
  }
  do {
    long long dist1[10], dist2[10];
    long long ang1[10], ang2[10];
    for (int i = (0); i < ((int)(4)); i++) {
      dist1[i] = dist(p[i], p[(i + 1) % 4]);
      ang1[i] = ang(p[i], p[(i + 1) % 4], p[(i + 3) % 4]);
      dist2[i] = dist(p[i + 4], p[(i + 1) % 4 + 4]);
      ang2[i] = ang(p[i + 4], p[(i + 1) % 4 + 4], p[(i + 3) % 4 + 4]);
    }
    if (dist1[0] == dist1[1] && dist1[1] == dist1[2] && dist1[2] == dist1[3]) {
      if (dist2[0] == dist2[2] && dist2[1] == dist2[3]) {
        bool found = false;
        for (int i = (0); i < ((int)(4)); i++) {
          if (ang1[i] != 0) found = true;
          if (ang2[i] != 0) found = true;
        }
        if (!found) {
          cout << "YES" << endl;
          for (int i = (0); i < ((int)(4)); i++) {
            if (i) cout << ' ';
            cout << p[i] + 1;
          }
          cout << endl;
          for (int i = (0); i < ((int)(4)); i++) {
            if (i) cout << ' ';
            cout << p[i + 4] + 1;
          }
          cout << endl;
          return 0;
        }
      }
    }
  } while (next_permutation(p, p + n));
  cout << "NO" << endl;
}
