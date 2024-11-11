#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  vector<int> value(m + 1, 0);
  vector<int> time(m + 1, 1000);
  for (int i = 0; i < n; i++) {
    int l, r, t, a;
    cin >> l >> r >> t >> a;
    for (int j = l - 1; j < r; j++) {
      if (time[j] > t) {
        time[j] = t;
        value[j] = a;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < m; i++) sum += value[i];
  cout << sum;
  return 0;
}
