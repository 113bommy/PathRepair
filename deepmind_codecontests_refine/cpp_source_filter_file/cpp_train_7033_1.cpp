#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[100000];
int prp[100000];
bool ok(int c) {
  vector<pair<int, int> > pass;
  set<int> seen;
  for (int i = c - 1; i >= 0; --i) {
    if (!d[i]) continue;
    if (seen.find(d[i]) == seen.end()) {
      seen.insert(d[i] - 1);
      pass.emplace_back(i, d[i] - 1);
    }
  }
  if (seen.size() < m) return 0;
  reverse(pass.begin(), pass.end());
  int prpdays = 0;
  int prv = -1;
  for (auto i : pass) {
    prpdays += i.first - prv - 1;
    if (prpdays < prp[i.second]) return 0;
    prpdays -= prp[i.second];
    prv = i.first;
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> prp[i];
  }
  int l = m, h = n;
  while (l < h) {
    int m = (l + h) / 2;
    if (ok(m))
      h = m;
    else
      l = m + 1;
  }
  if (!ok(h)) h = -1;
  cout << h << '\n';
  return 0;
}
