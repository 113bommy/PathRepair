#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, SQ = 350;
int arr[N], temp[N];
vector<pair<pair<int, int>, int> > s;
int id[N];
void del(int id) {
  int sz = s.size();
  vector<pair<pair<int, int>, int> > c;
  for (int i = sz - 1; i > id; i--) {
    c.push_back(s[i]);
    s.pop_back();
  }
  s.pop_back();
  sz = c.size();
  for (int i = sz - 1; i >= 0; i--) {
    s.push_back(c[i]);
    c.pop_back();
  }
  return;
}
void ins(int id, int l, int r, int v) {
  if (l == r) return;
  int sz = s.size();
  vector<pair<pair<int, int>, int> > c;
  for (int i = sz - 1; i >= id; i--) {
    c.push_back(s[i]);
    s.pop_back();
  }
  s.push_back({{l, r}, v});
  sz = c.size();
  for (int i = sz - 1; i >= 0; i--) {
    s.push_back(c[i]);
    c.pop_back();
  }
  return;
}
void add(int v, int c) {
  int sz = s.size(), i = 0, seen = 0;
  while (i < sz and s[i].second < v and
         seen + s[i].first.second - s[i].first.first <= c) {
    seen += s[i].first.second - s[i].first.first;
    i++;
  }
  if (sz == 0) {
    s.push_back({{-1, 0}, v});
    return;
  }
  if (i == sz) {
    s.push_back({{-1, 0}, v});
    return;
  }
  int l = s[i].first.first, r = s[i].first.second, mxL = -1, mxR = -1, lp = l,
      vl = s[i].second;
  if (l != -1) {
    while (seen <= c and arr[l] < v) {
      l++;
      seen++;
    }
    del(i);
    for (int j = lp; j < l; j++) mxL = max(mxL, arr[j]);
    for (int j = l; j < r; j++) mxR = max(mxR, arr[j]);
    ins(i, lp, l, mxL);
    if (l > lp)
      ins(i + 1, -1, 0, v);
    else
      ins(i, -1, 0, v);
    if (l > lp)
      ins(i + 2, l, r, mxR);
    else
      ins(i + 1, l, r, mxR);
  } else {
    ins(i, -1, 0, v);
  }
}
void relax() {
  int sz = 0;
  for (auto X : s) {
    int l = X.first.first, r = X.first.second, val = X.second;
    if (l == -1)
      temp[sz++] = val;
    else {
      for (int i = l; i < r; i++) temp[sz++] = arr[i];
    }
  }
  s.clear();
  for (int i = 0; i < sz; i++) arr[i] = temp[i];
  int cnt = (sz + SQ - 1) / SQ;
  for (int i = 0; i < cnt; i++) {
    int l = i * SQ, r = min((i + 1) * SQ, sz);
    int mx = -1;
    for (int j = l; j < r; j++) mx = max(mx, arr[j]);
    s.push_back({{l, r}, mx});
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v, c;
    cin >> v >> c;
    id[v] = i + 1;
    add(v, c);
    if (i > 0 and i % SQ == 0) relax();
  }
  relax();
  for (int i = n - 1; i >= 0; i--) cout << id[arr[i]] << ' ';
  cout << '\n';
}
