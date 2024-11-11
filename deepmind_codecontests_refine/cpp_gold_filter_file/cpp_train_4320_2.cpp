#include <bits/stdc++.h>
using namespace std;
void solve(const vector<int>& xs) {
  stack<int> s;
  auto n = xs.size();
  vector<int> ls(n, -1);
  vector<int> rs(n, n);
  for (auto i = 0; i < n; ++i) {
    while (!s.empty() && xs[s.top()] >= xs[i]) {
      s.pop();
    }
    if (!s.empty()) {
      ls[i] = s.top();
    }
    s.push(i);
  }
  s = stack<int>();
  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && xs[s.top()] >= xs[i]) {
      s.pop();
    }
    if (!s.empty()) {
      rs[i] = s.top();
    }
    s.push(i);
  }
  vector<int> ys(n + 1, 0);
  for (auto i = 0; i < n; ++i) {
    auto t = rs[i] - ls[i] - 1;
    ys[t] = max(ys[t], xs[i]);
  }
  for (auto i = n - 1; i >= 1; --i) {
    ys[i] = max(ys[i], ys[i + 1]);
  }
  for (auto i = 1; i <= n; ++i) {
    cout << ys[i] << ' ';
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> xs(n, 0);
  for (auto i = 0; i < n; ++i) {
    cin >> xs[i];
  }
  solve(xs);
  return 0;
}
