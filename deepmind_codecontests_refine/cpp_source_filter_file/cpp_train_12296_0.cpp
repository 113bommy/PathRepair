#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
struct Box {
  int id, kon, color;
  bool operator<(const Box& other) const { return kon < other.kon; }
};
void solve() {
  int n, s, k;
  cin >> n >> s >> k;
  vector<Box> a(n);
  for (auto& b : a) cin >> b.kon;
  string strtmp;
  cin >> strtmp;
  for (int i = 0; i < n; ++i) {
    a[i].id = i + 1;
    a[i].color = (int)strtmp[i];
  }
  sort(a.begin(), a.end());
  vector<vector<int> > d(n, vector<int>(k, inf));
  int result = inf;
  for (int i = 0; i < n; ++i) {
    int kon = a[i].kon, steps = abs(i + 1 - s);
    if (kon < k)
      d[i][kon] = steps;
    else
      result = min(result, steps);
  }
  for (int kon = 1; kon < k; ++kon)
    for (int box = 0; box < n; ++box)
      if (d[box][kon] != inf) {
        for (int i = box + 1; i < n; ++i) {
          if ((a[i].color == a[box].color) || (a[i].kon <= a[box].kon))
            continue;
          int steps = abs(a[i].id - a[box].id) + d[box][kon];
          int newKon = kon + a[i].kon;
          if (newKon >= k)
            result = min(result, steps);
          else
            d[i][newKon] = min(d[i][newKon], steps);
        }
      }
  if (result == inf) result = -1;
  cout << result << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
