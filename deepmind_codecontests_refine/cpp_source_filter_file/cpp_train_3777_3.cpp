#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long int, int> &p1, pair<long long int, int> &p2) {
  if (p1.first < p2.first) {
    return true;
  } else if (p1.first > p2.first) {
    return false;
  } else if (p1.second > p2.second) {
    return false;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  vector<pair<long long int, int>> v;
  for (long long int i = 0; i < n; i++) {
    long long int x, y;
    cin >> x >> y;
    v.push_back({x, 1});
    v.push_back({y, 0});
  }
  sort(v.begin(), v.end(), cmp);
  long long int alive = 0;
  long long int year = v[0].first, max_alive = 0;
  for (long long int i = 0; i < int(v.size()); i++) {
    if (v[i].second == 1) {
      alive++;
      if (max_alive < alive) {
        max_alive = alive;
        year = v[i].first;
      }
    } else {
      alive--;
    }
  }
  cout << year << " " << max_alive << endl;
  return 0;
}
