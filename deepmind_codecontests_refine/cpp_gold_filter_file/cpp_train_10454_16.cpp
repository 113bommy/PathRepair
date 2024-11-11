#include <bits/stdc++.h>
using namespace std;
bool check(int k, int x, int n, int m, int i1, int i2, int l1, int l2, int j,
           int k1) {
  if (j * 2 + i1 + i2 > n) return false;
  if (k1 * 2 + l1 + l2 > m) return false;
  for (int i = 0; i < k - 2; i++) {
    int i3 = j + k1 + (i2 * l1);
    int i4 = i1;
    i1 = l1;
    i2 = l2;
    l1 = i4;
    j = k1;
    k1 = i3;
    if (k1 > x) return false;
  }
  if (k1 == x)
    return true;
  else
    return false;
}
string build(int n, int s, int i1, int i2) {
  string s1 = string(n, 'P');
  if (i1 == 1) s1[0] = 'C';
  if (i2 == 1) s1[n - 1] = 'A';
  for (int i = 0; i < s; i++) {
    s1[i1 + i * 2] = 'A';
    s1[i1 + i * 2 + 1] = 'C';
  }
  return s1;
}
int main() {
  int k, x, n, m;
  cin >> k >> x >> n >> m;
  for (int i1 = 0; i1 < 2; i1++) {
    for (int i2 = 0; i2 < 2; i2++) {
      for (int l1 = 0; l1 < 2; l1++) {
        for (int l2 = 0; l2 < 2; l2++) {
          for (int j = 0; j <= n / 2; j++) {
            for (int k1 = 0; k1 <= m / 2; k1++) {
              if (check(k, x, n, m, i1, i2, l1, l2, j, k1)) {
                string s1 = build(n, j, i1, i2);
                string s2 = build(m, k1, l1, l2);
                cout << s1 << endl << s2;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "Happy new year!";
  return 0;
}
