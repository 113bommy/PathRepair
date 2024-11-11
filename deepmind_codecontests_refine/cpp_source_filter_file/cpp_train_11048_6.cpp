#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> i, pair<int, int> j) {
  if (i.first == j.first) return i.second > j.second;
  return i.first > j.first;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, i, j;
  cin >> n;
  pair<int, int> x[n], y[n];
  for (i = 0; i < n; i++) {
    cin >> x[i].first >> x[i].second;
  }
  for (i = 0; i < n; i++) {
    cin >> y[i].first >> y[i].second;
  }
  sort(x, x + n);
  sort(y, y + 2, comp);
  cout << x[0].first + y[0].first << " " << x[0].second + y[0].second;
}
