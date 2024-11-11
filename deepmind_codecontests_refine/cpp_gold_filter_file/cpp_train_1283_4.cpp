#include <bits/stdc++.h>
using namespace std;
void prepare() {}
void solve() {
  int n, k;
  vector<int> s;
  cin >> n >> k;
  int t;
  vector<int> d(n + 1), v(n + 1), u(n + 1);
  s.reserve(n);
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    u[i] = t;
    v[abs(t)] += t > 0 ? 1 : -1;
    if (abs(t) == 1 && t > 0)
      ++d[1];
    else if (abs(t) != 1 && t < 0)
      ++d[1];
  }
  if (d[1] == k) s.push_back(1);
  for (int i = 2; i <= n; ++i) {
    d[i] = d[i - 1] + v[i] - v[i - 1];
    if (d[i] == k) s.push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (s.size() == 1) {
      if ((u[i] > 0 && d[abs(u[i])] == k) || (u[i] < 0 && d[abs(u[i])] != k))
        cout << "Truth" << endl;
      else
        cout << "Lie" << endl;
    } else {
      if (d[abs(u[i])] == k)
        cout << "Not defined" << endl;
      else if (u[i] > 0)
        cout << "Lie" << endl;
      else
        cout << "Truth" << endl;
    }
  }
}
int main() {
  prepare();
  solve();
  return 0;
}
