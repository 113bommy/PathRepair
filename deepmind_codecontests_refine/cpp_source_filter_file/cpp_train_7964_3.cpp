#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> fragments(n);
  for (int i = 0; i < n; i++) {
    fragments[i].first = i;
    cin >> fragments[i].second;
  }
  sort(fragments.begin(), fragments.end(),
       [](pair<int, int> p1, pair<int, int> p2) {
         return p1.second < p2.second;
       });
  long cost = 0;
  for (int i = 1; i < n; i++) {
    cost += abs(fragments[i].first - fragments[i - 1].first);
  }
  cout << cost << endl;
  return 0;
}
