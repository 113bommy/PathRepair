#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 5;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  vector<int> left(n, -1), right(n, n);
  vector<int> m;
  for (int i = 0; i < n; i++) {
    while (!m.empty() && v[m.back()] < v[i]) right[m.back()] = i, m.pop_back();
    m.push_back(i);
  }
  m.clear();
  for (int i = n - 1; i >= 0; i--) {
    while (!m.empty() && v[m.back()] <= v[i]) left[m.back()] = i, m.pop_back();
    m.push_back(i);
  }
  vector<vector<int> > bitsl(32, vector<int>(n, -1)),
      bitsr(32, vector<int>(n, n));
  for (int b = 0; b < 32; b++) {
    m.clear();
    for (int i = 0; i < n; i++) {
      if (v[i] & (1 << b))
        while (!m.empty()) bitsr[b][m.back()] = i, m.pop_back();
      else
        m.push_back(i);
    }
    m.clear();
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] & (1 << b))
        while (!m.empty()) bitsl[b][m.back()] = i, m.pop_back();
      else
        m.push_back(i);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int r = right[i] - 1, l = left[i] + 1;
    if (r == l) continue;
    int lor = -1;
    for (int b = 0; b < 32; b++) lor = max(bitsl[b][i], lor);
    if (lor >= l) {
      long long sx = lor - l + 1;
      long long dx = r - i + 1;
      ans += sx * dx;
      l = lor + 1;
    }
    int ror = n;
    for (int b = 0; b < 32; b++) ror = min(bitsr[b][i], ror);
    if (ror <= r) {
      long long dx = r - ror + 1;
      long long sx = i - l + 1;
      ans += sx * dx;
    }
  }
  cout << ans;
}
