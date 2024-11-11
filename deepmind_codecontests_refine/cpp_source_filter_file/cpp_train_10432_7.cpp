#include <bits/stdc++.h>
using namespace std;
bool v[2011], d[2011], m[2011][2011];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(n); ++j) {
      char c;
      cin >> c;
      m[i][j] = (c == '1');
    }
  int count = 0;
  for (int i = 0; i < int(n); ++i) {
    bool f = false;
    for (int j = n - 1; j > i; --j)
      if (m[i][j] && (!v[j] ^ f)) {
        ("%d %d\n", i, j), ++count;
        d[i] ^= 1;
        d[j] ^= 1;
        v[j] ^= 1;
        f ^= 1;
      }
  }
  memset(v, 0, sizeof v);
  for (int i = n - 1; i >= 0; --i) {
    bool f = false;
    for (int j = 0; j < i; ++j)
      if (m[i][j] && (!v[j] ^ f)) {
        ("%d %d\n", i, j), ++count;
        d[i] ^= 1;
        d[j] ^= 1;
        v[j] ^= 1;
        f ^= 1;
      }
  }
  for (int i = 0; i < int(n); ++i)
    if (m[i][i] != d[i]) ("%d %d\n", i, i), ++count;
  cout << count << endl;
}
