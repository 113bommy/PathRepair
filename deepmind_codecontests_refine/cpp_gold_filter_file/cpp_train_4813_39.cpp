#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int t, a, b, c;
int best;
int ba, bb, bc;
vector<int> v;
pair<int, int> disa(int x) {
  v.clear();
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) v.push_back(i);
  }
  int sz = v.size();
  for (int i = sz - 1; i >= 0; i--) v.push_back(x / v[i]);
  int mini = 1000000000;
  int mina = -1;
  for (int i = 0; i < int(v.size()); i++) {
    if (abs(a - v[i]) < mini) {
      mini = abs(a - v[i]);
      mina = v[i];
    }
  }
  return make_pair(mini, mina);
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    best = 1000000000;
    for (int i = 1; i <= int(20000); i++) {
      int cost = abs(b - i);
      pair<int, int> temp = disa(i);
      int nxt = ((c + i - 1) / i) * i;
      int prev = -1000000000;
      if (nxt > i) prev = nxt - i;
      int near = ((abs(c - nxt) < abs(c - prev)) ? nxt : prev);
      if (cost + temp.first + abs(c - near) < best) {
        best = cost + temp.first + abs(c - near);
        ba = temp.second;
        bb = i;
        bc = near;
      }
    }
    cout << best << '\n';
    cout << ba << " " << bb << " " << bc << '\n';
  }
}
