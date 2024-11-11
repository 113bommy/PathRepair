#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > ranges;
pair<int, int> rr[200001];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    rr[i] = {a, b};
    ranges.push_back({a, {1, i}});
    ranges.push_back({b + 1, {-1, i}});
  }
  sort(ranges.begin(), ranges.end());
  ranges.push_back({1000000007, {0, 0}});
  int buf = 0, last_one = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (last_one < rr[ranges[i].second.second].first &&
        ranges[i].second.first == -1) {
      cout << ranges[i].second.second;
      exit(0);
    }
    buf += ranges[i].second.first;
    if (buf == 1 && ranges[i].first != ranges[i + 1].first) {
      last_one = ranges[i].first;
    }
  }
  cout << "-1";
  return 0;
}
