#include <bits/stdc++.h>
using namespace std;
int d[4][109];
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size();
  auto get = [=](int a) { return 2 * (s1[a] == 'X') + (s2[a] == 'X'); };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      d[j][i] = -300;
    }
  }
  d[get(0)][0] = 0;
  for (int i = 1; i < n; i++) {
    if ((1 & get(i)) == 0) {
      d[1 | get(i)][i] = max(d[1 | get(i)][i], d[0][i - 1] + 1);
    }
    if ((2 & get(i)) == 0) {
      d[2 | get(i)][i] = max(d[2 | get(i)][i], d[0][i - 1] + 1);
    }
    if (get(i) == 0) {
      d[3][i] = max(d[3][i], d[1][i - 1] + 1);
      d[3][i] = max(d[3][i], d[2][i - 1] + 1);
    }
    for (int j = 0; j < 4; j++) {
      d[get(i)][i] = max(d[get(i)][i], d[j][i - 1]);
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    ans = max(ans, d[i][n - 1]);
  }
  cout << ans;
}
