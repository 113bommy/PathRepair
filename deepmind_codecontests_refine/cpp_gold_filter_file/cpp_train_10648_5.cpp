#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
const int MAXN = 2e5 + 10;
int n, c, d = 0, ans = 0;
vector<int> a;
vector<int> indexes[MAXN];
vector<int> last, katiret;
unordered_map<int, int> ctr;
void calcIndexes() {
  for (int i = 0; i < n; i++) indexes[a[i]].push_back(i);
}
void calcLast() {
  last.resize(n);
  int cur = -1;
  for (int i = 0; i < n; i++) {
    last[i] = cur;
    if (a[i] == d) cur = i;
  }
}
void calcNext() {
  katiret.resize(n);
  int cur = n;
  for (int i = n - 1; i >= 0; i--) {
    katiret[i] = cur;
    if (a[i] == d) cur = i;
  }
}
void calcOrder(int ind, vector<int> &order) {
  int el = a[ind], need = ctr[el] + 1;
  vector<int> l, r;
  int j = last[ind];
  while (l.size() < need) {
    l.push_back(j);
    if (*l.rbegin() == -1) break;
    j = last[j];
  }
  j = katiret[ind];
  while (r.size() < need) {
    r.push_back(j);
    if (*r.rbegin() == n) break;
    j = katiret[j];
  }
  reverse((l).begin(), (l).end());
  l.insert(l.end(), r.begin(), r.end());
  int sz = indexes[el].size() + l.size();
  order.resize(sz);
  merge((indexes[el]).begin(), (indexes[el]).end(), (l).begin(), (l).end(),
        order.begin());
}
void calcPfl(vector<int> &order, vector<int> &pfl) {
  int sum = 0;
  for (int i = 0; i < order.size(); i++) {
    if (i > 0) pfl.push_back(sum);
    if (0 <= order[i] && order[i] < n) {
      if (a[order[i]] == d)
        sum++;
      else if (a[order[i]] != d)
        sum--;
    }
  }
}
void calcPfr(vector<int> &order, vector<int> &pfr) {
  int sum = 0;
  for (int i = 0; i < order.size() - 1; i++) {
    if (0 <= order[i] && order[i] < n) {
      if (a[order[i]] == d)
        sum++;
      else if (a[order[i]] != d)
        sum--;
    }
    pfr.push_back(sum);
  }
}
void smartSolve(int ind) {
  int el = a[ind], need = ctr[el] + 1;
  vector<int> order;
  calcOrder(ind, order);
  vector<int> pfl, pfr;
  calcPfl(order, pfl);
  calcPfr(order, pfr);
  int maxpfsum = 3 * c + 10;
  vector<int> last(2 * maxpfsum, -2);
  for (int j = 0; j < pfr.size(); j++)
    if (last[pfr[j] + maxpfsum] == -2) last[pfr[j] + maxpfsum] = order[j];
  for (int j = 0; j < pfl.size(); j++)
    if (last[pfl[j] + maxpfsum] != -2 && order[j] >= ind &&
        last[pfl[j] + maxpfsum] <= ind)
      ans = max(ans, order[j + 1] - 1 - last[pfl[j] + maxpfsum]);
}
void stupidSolve(int el) {
  if (el == d) return;
  vector<int> pf(n);
  if (a[0] == el) pf[0]++;
  if (a[0] == d) pf[0]--;
  for (int j = 1; j < n; j++) {
    if (a[j] == el) pf[j]++;
    if (a[j] == d) pf[j]--;
    pf[j] += pf[j - 1];
  }
  vector<int> last(2 * n, -1);
  for (int j = 0; j < n; j++)
    if (last[pf[j] + n] == -1) last[pf[j] + n] = j;
  for (int j = 0; j < n; j++) {
    if (pf[j] == 0)
      ans = max(ans, j + 1);
    else if (last[pf[j] + n] != -1)
      ans = max(ans, j - last[pf[j] + n]);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  a.resize(n);
  for (auto &i : a) cin >> i;
  for (auto &i : a) ctr[i]++;
  for (auto &i : ctr)
    if (i.second > ctr[d]) d = i.first;
  calcIndexes();
  calcLast();
  calcNext();
  c = 180;
  int last = -1;
  for (auto &i : ctr) {
    if (i.first == d) continue;
    if (i.second >= c)
      stupidSolve(i.first);
    else
      for (auto &j : indexes[i.first]) smartSolve(j);
  }
  cout << ans;
  return 0;
}
