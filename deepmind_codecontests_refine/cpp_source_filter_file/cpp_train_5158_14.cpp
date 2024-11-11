#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int r[5] = {0};
  for (int i = 1; i <= m; i++) r[i % 5]++;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 5 == 0)
      cnt += r[0];
    else if (i % 5 == 1)
      cnt += r[4];
    else if (i % 5 == 2)
      cnt += r[3];
    else if (i % 5 == 3)
      cnt += r[2];
    else if (i % 5 == 4)
      cnt += r[1];
  }
  cout << cnt << endl;
  return 0;
}
