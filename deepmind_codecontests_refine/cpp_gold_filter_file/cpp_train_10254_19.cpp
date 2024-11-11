#include <bits/stdc++.h>
using namespace std;
int n;
char a[1000005], b[1000005];
inline bool Ok(int l1, int r1, int l2, int r2) {
  int len = (r1 - l1 + 1), j;
  for (j = 1; j <= len && a[l1 + j - 1] == b[l2 + j - 1]; ++j)
    ;
  if (j == len + 1) return true;
  if (len % 2) return false;
  int m1 = (l1 + r1) / 2, m2 = (l2 + r2) / 2;
  return ((Ok(l1, m1, l2, m2) && Ok(m1 + 1, r1, m2 + 1, r2)) ||
          (Ok(l1, m1, m2 + 1, r2) && Ok(m1 + 1, r1, l2, m2)));
}
int main() {
  int i, j;
  cin.sync_with_stdio(0);
  cin >> (a + 1) >> (b + 1);
  n = strlen(a + 1);
  if (Ok(1, n, 1, n))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
