#include <bits/stdc++.h>
using namespace std;
bool sp(pair<int, int> a, pair<int, int> b) {
  if (a.first * b.first + a.second * b.second == 0) return true;
  return false;
}
int main() {
  int a[8][2], i, j, k, l, i1, j1, k1, l1, x;
  pair<int, int> v1, v2, v3, v4, v5;
  for (i = 0; i < 8; i++) cin >> a[i][0] >> a[i][1];
  for (i = 0; i < 5; i++)
    for (j = i + 1; j < 6; j++)
      for (k = j + 1; k < 7; k++)
        for (l = k + 1; l < 8; l++) {
          bool b = false, b1 = false;
          v1.first = a[j][0] - a[i][0];
          v1.second = a[j][1] - a[i][1];
          v2.first = a[k][0] - a[i][0];
          v2.second = a[k][1] - a[i][1];
          v3.first = a[l][0] - a[i][0];
          v3.second = a[l][1] - a[i][1];
          if (sp(v1, v2) && v1.first * v1.first + v1.second * v1.second ==
                                v2.first * v2.first + v2.second * v2.second) {
            v4.first = a[j][0] - a[l][0];
            v4.second = a[j][1] - a[l][1];
            v5.first = a[k][0] - a[l][0];
            v5.second = a[k][1] - a[l][1];
            if (sp(v4, v5) && v4.first * v4.first + v4.second * v4.second ==
                                  v5.first * v5.first + v5.second * v5.second)
              b = true;
          }
          if (sp(v1, v3) && v1.first * v1.first + v1.second * v1.second ==
                                v3.first * v3.first + v3.second * v3.second) {
            v4.first = a[j][0] - a[k][0];
            v4.second = a[j][1] - a[k][1];
            v5.first = a[l][0] - a[k][0];
            v5.second = a[l][1] - a[k][1];
            if (sp(v4, v5) && v4.first * v4.first + v4.second * v4.second ==
                                  v5.first * v5.first + v5.second * v5.second)
              b = true;
          }
          if (sp(v2, v3) && v2.first * v2.first + v2.second * v2.second ==
                                v3.first * v3.first + v3.second * v3.second) {
            v2.first = a[k][0] - a[j][0];
            v2.second = a[k][1] - a[j][1];
            v3.first = a[l][0] - a[j][0];
            v3.second = a[l][1] - a[j][1];
            if (sp(v4, v5) && v4.first * v4.first + v4.second * v4.second ==
                                  v5.first * v5.first + v5.second * v5.second)
              b = true;
          }
          if (b) {
            x = 0;
            while (x == i || x == j || x == k || x == l) x++;
            i1 = x;
            x++;
            while (x == i || x == j || x == k || x == l) x++;
            j1 = x;
            x++;
            while (x == i || x == j || x == k || x == l) x++;
            k1 = x;
            x++;
            while (x == i || x == j || x == k || x == l) x++;
            l1 = x;
            v1.first = a[j1][0] - a[i1][0];
            v1.second = a[j1][1] - a[i1][1];
            v2.first = a[k1][0] - a[i1][0];
            v2.second = a[k1][1] - a[i1][1];
            v3.first = a[l1][0] - a[i1][0];
            v3.second = a[l1][1] - a[i1][1];
            if (sp(v1, v2)) {
              v4.first = a[j1][0] - a[l1][0];
              v4.second = a[j1][1] - a[l1][1];
              v5.first = a[k1][0] - a[l1][0];
              v5.second = a[k1][1] - a[l1][1];
              if (sp(v4, v5) &&
                  v2.first * v2.first + v2.second * v2.second ==
                      v4.first * v4.first + v4.second * v4.second &&
                  v1.first * v1.first + v1.second * v1.second ==
                      v5.first * v5.first + v5.second * v5.second)
                b1 = true;
            }
            if (sp(v1, v3)) {
              v4.first = a[j1][0] - a[k1][0];
              v4.second = a[j1][1] - a[k1][1];
              v5.first = a[l1][0] - a[k1][0];
              v5.second = a[l1][1] - a[k1][1];
              if (sp(v4, v5) &&
                  v3.first * v3.first + v3.second * v3.second ==
                      v4.first * v4.first + v4.second * v4.second &&
                  v1.first * v1.first + v1.second * v1.second ==
                      v5.first * v5.first + v5.second * v5.second)
                b1 = true;
            }
            if (sp(v2, v3)) {
              v4.first = a[k1][0] - a[j1][0];
              v4.second = a[k1][1] - a[j1][1];
              v5.first = a[l1][0] - a[j1][0];
              v5.second = a[l1][1] - a[j1][1];
              if (sp(v4, v5) &&
                  v2.first * v2.first + v2.second * v2.second ==
                      v5.first * v5.first + v5.second * v5.second &&
                  v3.first * v3.first + v3.second * v3.second ==
                      v4.first * v4.first + v4.second * v4.second)
                b1 = true;
            }
            if (b1) {
              cout << "YES\n";
              cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1
                   << "\n";
              cout << i1 + 1 << " " << j1 + 1 << " " << k1 + 1 << " " << l1 + 1
                   << "\n";
              return 0;
            }
          }
        }
  cout << "NO";
  return 0;
}
