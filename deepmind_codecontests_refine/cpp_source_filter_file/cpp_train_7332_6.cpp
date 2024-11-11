#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  map<long double, vector<int>> cities;
  for (int i = 0; i < n; ++i) {
    int x, y, k;
    cin >> x >> y >> k;
    long long int sum = x * x + y * y;
    long double R = sqrt(sum);
    cities[R].push_back(k);
  }
  for (auto &it : cities) {
    for (auto pop : it.second) {
      s += pop;
      if (s > 1000000) {
        cout << setprecision(8) << it.first << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
