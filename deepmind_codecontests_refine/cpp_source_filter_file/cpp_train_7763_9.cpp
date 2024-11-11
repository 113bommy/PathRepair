#include <bits/stdc++.h>
using namespace std;
int grundy[65];
int main() {
  int k = 1, times = 2, g = 1;
  while (k < 60) {
    for (int i = 0; i < times; i++) {
      grundy[k++] = g;
      if (k == 60) break;
    }
    times++;
    g++;
  }
  int n, t, s;
  cin >> n;
  t = 0;
  for (int i = 0; i < n; i++) {
    cin >> s;
    t ^= grundy[s];
  }
  if (t == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
