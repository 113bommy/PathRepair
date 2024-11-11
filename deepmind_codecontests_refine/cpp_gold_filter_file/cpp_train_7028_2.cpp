#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, h, j, i, n, t[102], r[102];
  long long p;
  cin >> n;
  for (i = 0; i < 102; i++) {
    t[i] = 0;
    r[i] = 0;
  }
  h = 0;
  s = n;
  for (j = 0; j < n + 1; j++) {
    cin >> t[j];
    if (t[j] == 1) {
      r[h] = j;
      h = h + 1;
      s = s - 1;
    }
  }
  p = 1;
  for (i = 0; i < h + 1; i++) {
    if ((r[i + 1] - r[i]) > 0) p = p * (r[i + 1] - r[i]);
  }
  if (n == 1) p = t[0];
  if (s == n) p = 0;
  if (s == (n - 1)) p = 1;
  cout << p;
}
