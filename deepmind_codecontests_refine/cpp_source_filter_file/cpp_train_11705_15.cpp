#include <bits/stdc++.h>
using namespace std;
template <class X>
void input(vector<X>& a, int N) {
  X temp;
  for (long long int i = 0; i < N; i++) {
    cin >> temp;
    a.push_back(temp);
  }
}
void solve() {
  int a, b;
  cin >> a >> b;
  vector<pair<int, int>> x, y;
  for (long long int i = -1001; i < 1001; i++) {
    if (i != 0) {
      for (long long int j = -1001; j < 1001; j++) {
        if (j != 0) {
          if ((i * i + j * j) == a * a) {
            x.push_back(make_pair(i, j));
          }
          if ((i * i + j * j) == b * b) {
            y.push_back(make_pair(i, j));
          }
        }
      }
    }
  }
  for (auto i : x) {
    for (auto j : y) {
      int x1 = i.first;
      int x2 = j.first;
      int y1 = i.second;
      int y2 = j.second;
      if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == a * a + b * b &&
          (x1 != x2) && (y1 != y2)) {
        cout << "Yes" << '\n';
        cout << "0 0" << '\n';
        cout << x1 << " " << y1 << '\n';
        cout << x2 << " " << y2 << '\n';
        return;
      }
    }
  }
  cout << "No";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
