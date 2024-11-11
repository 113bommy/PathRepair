#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, y;
  cin >> n;
  pair<int, int> po[4 * n + 1];
  for (int i = 0; i < 4 * n + 1; ++i) {
    cin >> po[i].first >> po[i].second;
  }
  sort(po, po + 4 * n + 1);
  map<int, int> mx, my;
  for (auto e : po) {
    mx[e.first]++;
    my[e.second]++;
  }
  if (mx.begin()->second == 1) {
    cout << po[0].first << " " << po[0].second << "\n";
    return 0;
  } else if (mx.rbegin()->second == 1) {
    cout << po[4 * n].first << " " << po[4 * n].second << "\n";
    return 0;
  }
  if (my.begin()->second == 1) {
    for (int i = 0; i < 4 * n + 1; ++i) {
      if (po[i].second == my.begin()->first) {
        cout << po[i].first << " " << po[i].second << "\n";
        return 0;
      }
    }
  } else if (my.rbegin()->second == 1) {
    for (int i = 0; i < 4 * n + 1; ++i) {
      if (po[i].second == my.rbegin()->first) {
        cout << po[i].first << " " << po[i].second << "\n";
        return 0;
      }
    }
  }
  int l = po[0].first, r = po[4 * n].first;
  int k1 = my.begin()->first, k2 = my.rbegin()->first;
  int i = 0;
  while (po[i].first == l) {
    i++;
  }
  for (; i < 4 * n + 1; ++i) {
    if (po[i].second != k1 && po[i].second != k2) {
      cout << po[i].first << " " << po[i].second << "\n";
      return 0;
    }
  }
  return 0;
}
