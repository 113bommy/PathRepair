#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int cars_cnt, fs_cnt, distance, til_time;
  cin >> cars_cnt >> fs_cnt >> distance >> til_time;
  vector<pair<int, int>> cars;
  cars.reserve(cars_cnt);
  for (int i = 0; i < cars_cnt; i++) {
    int ci, vi;
    cin >> ci >> vi;
    cars.push_back(make_pair(vi, ci));
  }
  vector<int> gas_stations;
  gas_stations.reserve(fs_cnt);
  for (int i = 0; i < fs_cnt; i++) {
    int tmp;
    cin >> tmp;
    gas_stations.push_back(tmp);
  }
  gas_stations.push_back(distance);
  sort(gas_stations.begin(), gas_stations.end());
  sort(cars.begin(), cars.end());
  int l = -1, r = cars_cnt, m;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    int t = 0;
    int fuel_max = cars[m].first;
    int p = 0;
    int dist = 0;
    bool ok = true;
    while (p < gas_stations.size()) {
      int travel = gas_stations[p] - dist;
      if (travel > fuel_max) {
        ok = false;
        break;
      }
      t += 2 * travel - min(travel, fuel_max - travel);
      dist = gas_stations[p];
      p++;
    }
    if (t <= til_time && ok) {
      r = m;
    } else {
      l = m;
    }
  }
  int mm = 1000000001;
  for (int i = r; i < cars_cnt; i++) {
    if (cars[i].second < mm) {
      mm = cars[i].second;
    }
  }
  if (mm == 100000001) {
    cout << -1 << endl;
  } else {
    cout << mm << endl;
  }
}
