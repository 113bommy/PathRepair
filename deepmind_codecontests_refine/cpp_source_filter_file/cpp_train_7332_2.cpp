#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, p;
  cin >> n >> p;
  if (p >= 1000000) {
    cout << 0 << endl;
    return 0;
  }
  vector<pair<long long int, long long int>> cities;
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    cities.push_back({(long long int)pow(x, 2) + (long long int)pow(y, 2), c});
  }
  sort(cities.begin(), cities.end());
  int ind = 0;
  while (p < 1000000 && ind < n) {
    p += cities[ind].second;
    ind++;
  }
  if (p >= 1000000) {
    cout << fixed << setprecision(7) << sqrt(cities[ind].first) << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
