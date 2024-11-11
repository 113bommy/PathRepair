#include <bits/stdc++.h>
const double PI = 2.0 * acos(0.0);
using namespace std;
int b[2][105], n, m[2];
string t, p[2];
bool direction[2];
void kmp_preprocess() {
  for (int ip = 0; ip < 2; ip++) {
    int i = 0, j = -1;
    b[ip][0] = -1;
    while (i < m[ip]) {
      while (j >= 0 && p[ip][i] != p[ip][j]) j = b[ip][j];
      i++;
      j++;
      b[ip][i] = j;
    }
  }
}
void kmp_search() {
  for (int it = 0; it < 2; it++) {
    if (it == 1) reverse(t.begin(), t.end());
    int i = 0, j = 0, ip = 0;
    while (i < n && ip < 2) {
      while (j >= 0 && t[i] != p[ip][j]) j = b[ip][j];
      i++;
      j++;
      if (j == m[ip]) {
        ip++;
        j = 0;
      }
    }
    if (ip == 2) direction[it] = true;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int TC, i, j, l;
  cin >> t;
  cin >> p[0];
  cin >> p[1];
  n = t.length();
  m[0] = p[0].length();
  m[1] = p[1].length();
  kmp_preprocess();
  direction[0] = direction[1] = false;
  kmp_search();
  if (direction[0] && direction[1])
    cout << "both" << endl;
  else if (direction[0])
    cout << "forward" << endl;
  else if (direction[1])
    cout << "backward" << endl;
  else
    cout << "fantasy" << endl;
  return 0;
}
