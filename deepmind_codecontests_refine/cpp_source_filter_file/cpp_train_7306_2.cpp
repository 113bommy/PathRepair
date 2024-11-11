#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> d[200001];
int main() {
  int n, k;
  int ans = 0, em = 0;
  cin >> n >> k;
  map<vector<pair<int, int>>, int> a;
  for (int i = 0; i < n; i++) {
    int t;
    int c = 0, same = 1;
    cin >> t;
    while (t % 2 == 0) {
      c++;
      t = t / 2;
    }
    c %= k;
    if (c != 0) {
      d[i].push_back({2, c});
      if (c * 2 != k) same = 0;
    }
    for (int j = 3; j <= sqrt(t); j = j + 2) {
      c = 0;
      while (t % j == 0) {
        c++;
        t = t / j;
      }
      c %= k;
      if (c != 0) {
        d[i].push_back({j, c});
        if (c * 2 != k) same = 0;
      }
    }
    if (t > 2) {
      d[i].push_back({t, 1});
      if (k != 2) same = 0;
    }
    if (same) {
      em++;
    }
    a[d[i]]++;
  }
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> p;
    for (auto j : d[i]) {
      p.push_back({j.first, k - j.second});
    }
    ans += a[p];
  }
  cout << (ans - em) / 2 << endl;
  return 0;
}
