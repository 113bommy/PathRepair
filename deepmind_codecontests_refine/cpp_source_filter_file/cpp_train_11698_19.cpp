#include <bits/stdc++.h>
using namespace std;
int a[100002], t[10002], x[10002], y[10002];
pair<int, int> w[3];
vector<int> vec;
int main() {
  int i, j, k, l, m, n;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];
    if (t[i] == 1)
      w[1].first += x[i], w[1].second += x[i];
    else
      w[2].first += x[i], w[2].second += x[i];
  }
  if (w[1].first >= (w[1].first + w[1].second) / 2)
    cout << "LIVE\n";
  else
    cout << "DEAD\n";
  if (w[2].first >= (w[2].first + w[2].second) / 2)
    cout << "LIVE\n";
  else
    cout << "DEAD\n";
}
