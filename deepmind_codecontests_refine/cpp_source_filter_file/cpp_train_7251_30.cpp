#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  int ara[n + 2][2];
  for (int i = 1; i <= n; i++) {
    cin >> ara[i][0] >> ara[i][1];
  }
  bool found = false;
  int h, m;
  h = ara[1][0] - 0;
  m = ara[1][1] - 0;
  if (h * 60 + m >= (s + 1)) {
    cout << 0 << " " << s << endl;
    found = true;
  }
  for (int i = 1; i <= n && !found; i++) {
    h = ara[i + 1][0] - ara[i][0];
    m = ara[i + 1][1] - ara[i][1] - 1;
    if (m < 0) {
      h--;
      m = 60 + m;
    }
    int total = h * 60 + m;
    int need = 2 * s + 1;
    if (total >= need) {
      int hh = ara[i][0];
      int mm = ara[i][1];
      mm += s;
      mm++;
      hh += (mm / 60);
      mm = mm % 60;
      cout << hh << " " << mm << endl;
      found = true;
      break;
    }
  }
  if (!found) {
    int hhh = ara[n][0];
    int mmm = ara[n][1] + 1 + s;
    hhh += (mmm / 60);
    mmm %= 60;
    cout << hhh << " " << mmm << endl;
    found = true;
  }
  return 0;
}
