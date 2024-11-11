#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
  ios_base::sync_with_stdio(false);
  vector<int> rasp;
  int n, k, p, x, y, lower = 0, gr = 0;
  cin >> n >> k >> p >> x >> y;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    x -= a[i];
    if (a[i] >= y)
      gr++;
    else
      lower++;
  }
  while (lower < n / 2) {
    lower++;
    rasp.push_back(1);
    x--;
    k++;
  }
  while (k < n) {
    k++;
    rasp.push_back(y);
    x -= y;
  }
  if (y == 1 && x >= 0) {
    for (auto el : rasp) cout << el << " ";
  } else if (x < 0 || lower >= n / 2 + 1)
    cout << -1;
  else {
    for (auto el : rasp) cout << el << " ";
  }
  return 0;
}
