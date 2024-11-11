#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  pair<long long int, long long int> p[m];
  for (int i = 0; i < (m); ++i) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }
  long long int ans = INT_MIN;
  ans = max(ans, max((long long int)0, p[0].second + p[0].first));
  for (int i = 0; i < m - 1; i++) {
    long long int d1 = p[i].first, h1 = p[i].second;
    long long int d2 = p[i + 1].first, h2 = p[i + 1].second;
    long long int x = d2 - d1;
    if (h1 <= h2) {
      if (h2 - h1 <= x) {
        long long int y = x - (h2 - h1);
        ans = max(ans, h2 + (y / 2));
      } else {
        cout << "IMPOSSIBLE";
        return 0;
      }
    } else if (h1 > h2) {
      if (h1 - h2 <= x) {
        long long int y = (x - (h1 - h2));
        ans = max(ans, h1 + y / 2);
      } else {
        cout << "IMPOSSIBLE";
        return 0;
      }
    }
  }
  ans = max(ans, max((long long int)0, p[m - 1].second + (m - p[m - 1].first)));
  cout << ans;
}
