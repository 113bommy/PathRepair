#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long idex[m], s[m];
  for (int i = 0; i < m; i++) {
    cin >> idex[i] >> s[i];
  }
  bool p = 0;
  long long x = 0;
  long long y[m + 1], k = 1;
  for (int i = 1; i < m; i++) {
    if (abs(s[i] - s[i - 1]) > idex[i] - idex[i - 1]) {
      p = 1;
      break;
    }
    if (s[i - 1] > s[i])
      y[k] = (abs(idex[i] - idex[i - 1]) + s[i] - s[i - 1]) / 2 + s[i - 1];
    else
      y[k] = (abs(idex[i] - idex[i - 1]) + s[i - 1] - s[i]) / 2 + s[i];
    k++;
  }
  if (idex[m - 1] != n) {
    y[m] = n - idex[m - 1] + s[m - 1] - 1;
  } else
    y[m] = 0;
  y[0] = s[0] + idex[0] - 1;
  if (p == 1)
    cout << "IMPOSSIBLE";
  else {
    for (int i = 0; i < m + 1; i++) {
      if (x < y[i]) x = y[i];
    }
    for (int i = 0; i < m; i++) {
      if (x < s[i]) x = s[i];
    }
    cout << x;
  }
}
