#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>> v(n);
  for (auto &e : v) {
    cin >> e.second >> e.first;
    e.first--;
    e.second--;
  }
  sort(begin(v), end(v));
  int r = w, d = 0;
  for (auto e : v) {
    if (e.second - e.first == d) {
      d++;
    } else if (e.second - e.first > d) {
      r = min(r, e.second);
    }
  }
  cout << r << endl;
}
