#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MX = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, d;
  cin >> m >> d;
  vector<int> v = {1, 3, 5, 7, 8, 10, 12};
  int ans;
  if ((find(v.begin(), v.end(), m) != v.end()) && d <= 5)
    ans = 5;
  else if ((find(v.begin(), v.end(), m) != v.end()) && d > 5)
    ans = 6;
  else if ((find(v.begin(), v.end(), m) == v.end()) && m != 2 && d <= 6)
    ans = 5;
  else if ((find(v.begin(), v.end(), m) == v.end()) && m != 2 && d > 6)
    ans = 6;
  else if (m == 2 && d == 1)
    ans = 4;
  else
    ans = 5;
  cout << ans << endl;
  return 0;
}
