#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
map<pair<int, int>, bool> hh;
map<pair<int, int>, bool>::iterator itr;
int n;
void end_(long long x) {
  cout << x;
  exit(0);
}
void try_(int i1, int i2) {
  hh.clear();
  int r = v[i2].first - v[i1].first, i = i1, x;
  while (i < n) {
    hh[v[i]] = 1;
    x = v[i].first + r;
    i++;
    while (i < n && v[i].first != x) i++;
  }
  if ((int)(hh).size() < n - 1) return;
  if ((int)(hh).size() == n) end_(v[1].second);
  long long nn = n;
  long long ln = nn * (nn + 1) / 2LL, s = 0;
  for (itr = hh.begin(); itr != hh.end(); itr++) s += 1LL * (*itr).first.second;
  end_(ln - s);
}
int main() {
  cin >> n;
  v.resize(n);
  int i, j, z;
  for (i = 0; i < n; i++) cin >> v[i].first, v[i].second = i + 1;
  if (n == 2) end_(1);
  sort(v.begin(), v.end());
  try_(0, 1);
  try_(0, 2);
  try_(1, 2);
  end_(-1);
  return 0;
}
