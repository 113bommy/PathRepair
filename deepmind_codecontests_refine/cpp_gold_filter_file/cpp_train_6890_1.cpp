#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
const int NN = 2 * 1e5 + 3;
int a[NN], t[4 * NN];
void build(int v, int l, int r) {
  if (l == r - 1) {
    t[v] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(2 * v + 1, l, m);
  build(2 * v + 2, m, r);
  t[v] = t[2 * v + 1] + t[2 * v + 2];
}
int fnd(int v, int l, int r, int k) {
  if (k > t[v]) return -1;
  if (l == r - 1) return l;
  int m = (l + r) / 2;
  if (t[2 * v + 1] >= k)
    return fnd(2 * v + 1, l, m, k);
  else
    return fnd(2 * v + 2, m, r, k - t[2 * v + 1]);
}
void upd(int v, int l, int r, int id, int val) {
  if (l == r - 1) {
    t[v] = val;
    a[l] = val;
    return;
  }
  int m = (l + r) / 2;
  if (id < m)
    upd(2 * v + 1, l, m, id, val);
  else
    upd(2 * v + 2, m, r, id, val);
  t[v] = t[2 * v + 1] + t[2 * v + 2];
}
int sum(int v, int l, int r, int lf, int rg) {
  if (l == lf && r == rg) return t[v];
  int m = (l + r) / 2;
  int ans = 0;
  if (lf < m) ans += sum(2 * v + 1, l, m, lf, min(m, rg));
  if (rg > m) ans += sum(2 * v + 2, m, r, max(m, lf), rg);
  return ans;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  vector<pair<int, int>> del(n);
  for (int i = 0; i < n; ++i) del[i] = {v[i], i};
  sort(del.begin(), del.end(), cmp);
  int m;
  cin >> m;
  vector<pair<pair<int, int>, int>> vp;
  for (int i = 0; i < m; i++) {
    int k, pos;
    cin >> k >> pos;
    vp.push_back({{k, pos}, i});
  }
  sort(vp.begin(), vp.end(),
       [](pair<pair<int, int>, int> v1, pair<pair<int, int>, int> v2) {
         if (v1.first.first == v2.first.first &&
             v1.first.second == v2.first.second)
           return v1.second < v2.second;
         else if (v1.first.first == v2.first.first)
           return v1.first.second < v2.first.second;
         else
           return v1.first.first > v2.first.first;
       });
  for (int i = 0; i < n; ++i) a[i] = 1;
  build(0, 0, n);
  int j = 0;
  int cur = n;
  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    int kk = vp[i].first.first, poss = vp[i].first.second, id = vp[i].second;
    if (kk < cur) {
      while (cur > kk) {
        upd(0, 0, n, del[j].second, 0);
        j++;
        cur--;
      }
    }
    ans[id] = v[fnd(0, 0, n, poss)];
  }
  for (int i = 0; i < m; ++i) cout << ans[i] << endl;
  return 0;
}
