#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, x, y, mm = -1, i, s1;
  cin >> n >> s;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    if (x < s) {
      if ((100 - y) > mm && y != 0) mm = 100 - y;
    }
    if (x <= s && y == 0) mm = max(mm, 0);
  }
  cout << mm;
  return 0;
}
