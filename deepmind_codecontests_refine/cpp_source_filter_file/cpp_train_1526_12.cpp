#include <bits/stdc++.h>
using namespace std;
int n, a, b, m[257];
bool kt(int c, int d) {
  if (((c == a) && (d == b)) || (c == b) && (a == d))
    return true;
  else
    return false;
}
int kt1(int c, int d, int x) {
  if (c == x)
    return 1;
  else if (d == x)
    return 2;
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) m[i] = i;
  for (int i = 1; i <= 100; ++i) {
    n = n / 2;
    for (int j = 0; j < n; ++j)
      if (kt(m[j * 2 + 1], m[2 * j + 2])) {
        if (n == 1)
          cout << "FINAL!";
        else
          cout << i;
        return 0;
      } else if ((kt1(m[j * 2 + 1], m[2 * j + 2], a) == 1) ||
                 (kt1(m[j * 2 + 1], m[2 * j + 2], b) == 1))
        m[j + 1] = m[2 * j + 1];
      else
        m[j + 1] = m[2 * j + 2];
  }
  return 0;
}
