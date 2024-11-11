#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 1e18;
int main() {
  long long n, m, i;
  cin >> n >> m;
  vector<pair<int, int> > p(m, pair<int, int>(0, 0));
  vector<long long> a(n + 1, 0);
  for (i = 0; i < (m); i++) {
    cin >> p[i].first >> p[i].second;
    a[p[i].first]++;
    a[p[i].second]++;
  }
  long long x = 0, y = 0, z = 0;
  for (i = 1; i < (n + 1); i++) {
    if (a[i] == 1) {
      x++;
    } else if (a[i] == 2) {
      y++;
    } else if (a[i] > 2) {
      z++;
    } else
      ;
  }
  if (m == n - 1 && x == 2 && y == n - 2) {
    cout << "bus topology";
  } else if (m == n - 1 && z == 1 && x == n - 1) {
    cout << "star topology";
  } else if (m == n && y == n) {
    cout << "ring topology";
  } else {
    cout << "unknow topology";
  }
  return 0;
}
