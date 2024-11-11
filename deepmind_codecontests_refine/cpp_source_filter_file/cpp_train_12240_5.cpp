#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  int d, l;
  char s;
  cin >> n >> m >> k;
  l = (k - 1) / (2 * m);
  d = ((k - 1) % (2 * m)) / 2;
  if (k < n * m) {
    s = 'L';
  } else {
    s = 'R';
  }
  cout << l + 1 << ' ' << d + 1 << ' ' << s;
  return 0;
}
