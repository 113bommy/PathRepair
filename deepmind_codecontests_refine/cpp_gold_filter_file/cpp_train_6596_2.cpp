#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, k, D = 0;
  cin >> m >> k;
  vector<int> d(m), s(m);
  for (int i = 0; i < m; i++) {
    cin >> d[i];
    D += d[i];
  }
  int max = -1, index = -1;
  int V = 0, current_fuel = 0;
  for (int i = 0; i < m; i++) {
    cin >> s[i];
    current_fuel += s[i];
    if (s[i] > max) {
      max = s[i];
      index = i;
    }
    if (current_fuel < d[i]) {
      int ramdeni = ceil((d[i] - current_fuel) / double(max));
      current_fuel += ramdeni * s[index];
      V += ramdeni * k;
    }
    current_fuel -= d[i];
  }
  cout << V + D;
  return 0;
}
