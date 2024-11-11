#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<pair<long long, long long> > v, u;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, sum = 0, cnt = 0, m, flag = 0, e, i = 0, x = 0, y, z, w, j = 0,
               k = 0, mini = 1e9, maxi = -1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
    mini = min(mini, x);
    maxi = max(maxi, y);
  }
  for (int i = 0; i < n; i++) {
    if (v[i].first == mini && v[i].second == maxi) return cout << i + 1, 0;
  }
  cout << -1;
  return 0;
}
