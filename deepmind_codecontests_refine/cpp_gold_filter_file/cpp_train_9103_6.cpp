#include <bits/stdc++.h>
using namespace std;
int n;
long long x[10005];
long long y[10005];
vector<pair<int, int> > xorr1;
vector<pair<int, int> > xorr2;
vector<int> place(30, -1);
vector<bool> was(10005, false);
vector<int> need(10005, -1);
void initialization() {
  cin >> n;
  for (long long i = 0; i < n; ++i) cin >> x[i];
  for (long long i = 0; i < n; ++i) cin >> y[i];
}
void solve() {}
void print() {}
void flush() {}
void swapp(int i, int j, long long* x, vector<pair<int, int> >& xorr) {
  if (i == j) return;
  x[i] ^= x[j];
  xorr.push_back(make_pair(i, j));
  x[j] ^= x[i];
  xorr.push_back(make_pair(j, i));
  x[i] ^= x[j];
  xorr.push_back(make_pair(i, j));
}
void get_basis(long long* x, vector<pair<int, int> >& xorr, bool q) {
  int cur = 0;
  vector<bool> used(10005, false);
  int j = 29;
  while (j >= 0) {
    int i = cur;
    while (i < n && (used[i] || !((x[i] >> j) & 1))) ++i;
    if (i == n) {
      --j;
      continue;
    }
    used[cur] = true;
    if (i != cur) swapp(i, cur, x, xorr);
    if (q) place[j] = cur;
    for (int k = 0; k < n; ++k) {
      if (cur != k) {
        if ((x[k] >> j) & 1) {
          x[k] ^= x[cur];
          xorr.push_back(make_pair(k, cur));
        }
      }
    }
    ++cur;
    --j;
  }
}
int main() {
  ios::sync_with_stdio(0);
  initialization();
  solve();
  print();
  get_basis(x, xorr1, 1);
  get_basis(y, xorr2, 0);
  for (int i = 0; i < n; ++i) {
    if (y[i] == 0) continue;
    int cur = 0;
    vector<pair<int, int> > xorr;
    bool q = false;
    int p;
    for (int j = 29; j >= 0; --j) {
      if (((y[i] >> j) & 1) && place[j] >= 0) {
        if (!q) p = place[j];
        q = true;
        cur ^= x[place[j]];
        if (p != place[j]) xorr.push_back(make_pair(p, place[j]));
      }
    }
    if (!q || cur != y[i]) {
      cout << -1;
      return 0;
    }
    was[p] = true;
    need[i] = p;
    x[p] = y[i];
    for (int j = 0; j < xorr.size(); ++j) xorr1.push_back(xorr[j]);
  }
  for (int i = 0; i < n; ++i) {
    if (!was[i]) {
      x[i] ^= x[i];
      xorr1.push_back(make_pair(i, i));
    }
  }
  for (int i = 0; i < n; ++i) {
    if (need[i] >= 0) swapp(i, need[i], x, xorr1);
  }
  reverse(xorr2.begin(), xorr2.end());
  cout << xorr1.size() + xorr2.size() << endl;
  for (int i = 0; i < xorr1.size(); ++i)
    cout << xorr1[i].first + 1 << ' ' << xorr1[i].second + 1 << endl;
  for (int i = 0; i < xorr2.size(); ++i)
    cout << xorr2[i].first + 1 << ' ' << xorr2[i].second + 1 << endl;
  return 0;
}
