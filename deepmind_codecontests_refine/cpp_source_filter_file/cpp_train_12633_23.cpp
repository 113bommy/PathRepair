#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int aabs(int a) {
  if (a < 0) return -a;
  return a;
}
int n;
set<int> g[513];
int main() {
  long double x[513], y[513];
  x[0] = -3.0901699437494742410229341718282;
  y[0] = 9.5105651629515357211643933337938;
  x[1] = 0;
  y[1] = 0;
  x[2] = 10;
  y[2] = 0;
  x[3] = 5;
  y[3] = 15.388417685876267012851452880185;
  x[4] = 13.090169943749474241022934171828;
  y[4] = 9.5105651629515357211643933337938;
  cin >> n;
  for (int i = 5; i < 4 * n + 1; i++) {
    x[i] = x[i - 4] + 16.180339887498948482045868343656;
    y[i] = y[i - 4];
  }
  cout << 4 * n + 1 << '\n';
  cout.setf(ios::fixed);
  cout.precision(9);
  for (int i = 0; i < 4 * n + 1; i++) {
    cout << x[i] << ' ' << y[i] << '\n';
  }
  for (int i = 0; i < n; i++) {
    cout << i * 4 + 1 << ' ' << i * 4 + 2 << ' ' << i * 4 + 3 << ' '
         << i * 4 + 4 << ' ' << i * 4 + 5 << '\n';
  }
  for (int i = 0; i < n; i++) {
    g[4 * i + 0].insert(4 * i + 4);
    g[4 * i + 4].insert(4 * i + 0);
    g[4 * i + 1].insert(4 * i + 4);
    g[4 * i + 4].insert(4 * i + 1);
    g[4 * i + 1].insert(4 * i + 3);
    g[4 * i + 3].insert(4 * i + 1);
    g[4 * i + 3].insert(4 * i + 2);
    g[4 * i + 2].insert(4 * i + 3);
    g[4 * i + 0].insert(4 * i + 2);
    g[4 * i + 2].insert(4 * i + 0);
  }
  n = 4 * n + 1;
  vector<int> ans;
  stack<int> s;
  s.push(0);
  while (!s.empty()) {
    int t = s.top();
    if (g[t].size() == 0) {
      s.pop();
      ans.push_back(t);
    } else {
      int tt = *(g[t].begin());
      g[t].erase(tt);
      g[tt].erase(t);
      s.push(tt);
    }
  }
  for (int i = (int)ans.size() - 1; i >= 0; i--) {
    printf("%d ", ans[i] + 1);
  }
  return 0;
}
