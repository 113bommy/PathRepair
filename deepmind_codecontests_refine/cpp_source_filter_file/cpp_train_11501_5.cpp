#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, s;
  cin >> m >> s;
  if (s == 0) {
    if (m == 1) {
      cout << "0 0" << endl;
      return 0;
    } else {
      cout << "-1 -1" << endl;
      return 0;
    }
  }
  string max, mini;
  for (int i = 0; i < m; i++) {
    int t = min(9, s);
    max.push_back(t + '0');
    s -= t;
  }
  if (s > 0) {
    cout << "-1 -1" << endl;
    return 0;
  }
  for (int i = m - 1; i >= 0; i--) {
    mini.push_back(max[i]);
  }
  int j = 0;
  while (mini[j] == 0) {
    j++;
  }
  mini[0]++;
  mini[j]--;
  cout << mini << " " << max << endl;
  return 0;
}
