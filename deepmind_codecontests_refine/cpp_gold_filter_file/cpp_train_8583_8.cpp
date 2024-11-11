#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100100 + 100];
long long t[100100 + 100];
map<long long, int> mymap;
pair<int, int> T[4 * 100100];
long long d;
vector<long long> v;
int now;
int dp[100100];
int pre[100100];
void update(int id, int l, int r, int ql, int qr, int val, int i) {
  if (l > qr || r < ql) return;
  if (ql <= l && r <= qr) {
    T[id] = {val, i};
    return;
  }
  int mid = (l + r) >> 1;
  update(id << 1, l, mid, ql, qr, val, i);
  update(id << 1 | 1, mid + 1, r, ql, qr, val, i);
  if (T[id << 1].first > T[id << 1 | 1].first)
    T[id] = {T[id << 1].first, T[id << 1].second};
  else
    T[id] = {T[id << 1 | 1].first, T[id << 1 | 1].second};
}
pair<int, int> get(int id, int l, int r, int ql, int qr) {
  if (l > qr || r < ql) return {0, 0};
  if (ql <= l && r <= qr) return T[id];
  int mid = (l + r) >> 1;
  pair<int, int> getl = get(id << 1, l, mid, ql, qr);
  pair<int, int> getr = get(id << 1 | 1, mid + 1, r, ql, qr);
  if (getl.first > getr.first) return getl;
  return getr;
}
int findl(long long x) {
  int lo, hi, mid, tmp;
  tmp = -1;
  lo = 1;
  hi = x;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (t[mid] <= t[x] - d) {
      tmp = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  return tmp;
}
int findr(int x) {
  int lo, hi, mid, tmp;
  tmp = -1;
  lo = x;
  hi = now;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (t[mid] >= t[x] + d) {
      tmp = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  return tmp;
}
int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  now = 1;
  mymap[v[0]] = 1;
  t[now] = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i] != v[i - 1]) {
      now++;
      mymap[v[i]] = now;
      t[now] = v[i];
    }
  }
  for (int i = 1; i <= 4 * now; i++) T[i] = {0, 0};
  for (int i = 1; i <= n; i++) {
    int x = mymap[a[i]];
    int idl = findl(x);
    int idr = findr(x);
    pair<int, int> getl;
    if (idl == -1)
      getl = {0, 0};
    else
      getl = get(1, 1, now, 1, idl);
    pair<int, int> getr;
    if (idr == -1)
      getr = {0, 0};
    else
      getr = get(1, 1, now, idr, now);
    if (getl.first > getr.first) {
      dp[i] = getl.first + 1;
      pre[i] = getl.second;
    } else {
      dp[i] = getr.first + 1;
      pre[i] = getr.second;
    }
    update(1, 1, now, x, x, dp[i], i);
  }
  int id = 1;
  for (int i = 2; i <= n; i++)
    if (dp[i] > dp[id]) id = i;
  cout << dp[id] << endl;
  vector<int> ans;
  while (id) {
    ans.push_back(id);
    id = pre[id];
  }
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
  return 0;
}
