#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  double x, y;
  long long int sol;
  set<pair<double, double>> p;
  vector<pair<double, double>> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
    p.insert(v[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      pair<double, double> tempPair = make_pair(
          (v[i].first + v[j].first) / 2, (v[i].second + v[j].second) / 2);
      if (p.count(tempPair)) sol++;
    }
  }
  cout << sol;
  return 0;
}
