#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
const double pi = acos(-1.0);
enum {};
string w[5];
int k[11];
string s[11][21];
int z[200];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> w[i];
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> k[i];
    for (int j = 0; j < k[i]; ++j) cin >> s[i][j];
  }
  pair<int, int> r(-1, 1 << 28);
  int d[] = {0, 1, 2, 3};
  do {
    int x = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j)
        if (d[i] > d[j]) {
          ++x;
        }
    }
    for (int l = 0; l < m; ++l) {
      bool f = false;
      for (int i = 0, j = 0; i < n && j < k[l]; ++j)
        if (w[d[i]] == s[l][j]) {
          ++i;
          if (i == n) {
            f = true;
            break;
          }
        }
      int p = (n * (n - 1)) / 2 - x + 1;
      if (f && (p > r.first || p == r.first && l > r.second))
        r = pair<int, int>(p, l);
    }
  } while (next_permutation(d, d + (n)));
  if (r.first == -1) {
    cout << "Brand new problem!" << endl;
  } else {
    cout << r.second + 1 << endl;
    cout << "[:";
    for (int i = 0; i < r.first; ++i) cout << "|";
    cout << ":]" << endl;
  }
  return 0;
}
