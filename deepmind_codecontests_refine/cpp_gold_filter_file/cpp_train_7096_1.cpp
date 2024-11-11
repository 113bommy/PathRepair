#include <bits/stdc++.h>
using namespace std;
void no() { printf("NO\n"); }
void yes() { printf("YES\n"); }
const long long N = 1e5 + 5;
const long long M = 1e9 + 7;
void sol() {
  int n;
  int m;
  cin >> n;
  int con[n];
  vector<pair<int, int>> p;
  for (int i = 0; i < n; ++i) {
    con[i] = 0;
  }
  cin >> m;
  while (m--) {
    int x, y;
    int t;
    cin >> t;
    cin >> x >> y;
    --x;
    --y;
    if (t)
      con[x]++, con[y]--;
    else
      p.push_back({x, y});
  }
  int sum = 0;
  for (int i = 0; i + 1 < n; ++i) {
    sum += con[i];
    if (sum > 0)
      con[i] = 0;
    else
      con[i] = -1;
  }
  for (int i = 0; i < (int)p.size(); ++i) {
    bool ok = true;
    for (int j = p[i].first; j < p[i].second; ++j) {
      if (con[j] == -1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      no();
      return;
    }
  }
  yes();
  sum = 1000000;
  cout << sum << " ";
  for (int i = 1; i < n; ++i) {
    if (con[i - 1] == 0)
      sum++;
    else
      sum--;
    cout << sum << " \n"[i + 1 == n];
  }
}
int main() {
  int tc = 1;
  while (tc--) {
    sol();
  }
}
