#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n = 0, color[5000], count[5000], ans[5000];
  memset(color, 0, sizeof(int) * 5000);
  memset(ans, 0, sizeof(int) * 5000);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> color[i];
  for (int i = 0; i < n; ++i) {
    memset(count, 0, sizeof(int) * 5000);
    int curmax = 0, curmaxid = 0;
    for (int j = i; j < n; ++j) {
      ++count[color[j] - 1];
      if (count[color[j] - 1] > curmax) {
        curmax = count[color[j] - 1];
        curmaxid = color[j] - 1;
      }
      if (count[color[j] - 1] == curmax && color[j] - 1 < curmaxid)
        curmaxid = color[j] - 1;
      ++ans[curmaxid];
    }
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  return 0;
}
