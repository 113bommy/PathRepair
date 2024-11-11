#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793238463;
const long long int dx4[4] = {0, 1, 0, -1};
const long long int dy4[4] = {-1, 0, 1, 0};
const long long int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const long long int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> vec_splitter(string s) {
  for (char &c : s) c = c == ',' ? ' ' : c;
  stringstream ss;
  ss << s;
  vector<string> res;
  for (string z; ss >> z; res.push_back(z))
    ;
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) long long int idx) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long int idx, Head H, Tail... T) {
  if (idx > 0) cerr << ", ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, T...);
}
vector<long long int> h;
map<long long int, vector<pair<long long int, long long int>>> gx, gy;
const long long int MAXN = (long long int)1e5 + 5;
long long int tree[4 * MAXN];
void update(long long int id, long long int tl, long long int tr,
            long long int i, long long int val) {
  if (tl > tr or tr < i or tl > i) {
    return;
  }
  if (tl == tr) {
    tree[id] += val;
    return;
  }
  long long int tm = (tl + tr) / 2;
  if (i <= tm) {
    update(id * 2, tl, tm, i, val);
  } else {
    update(id * 2 + 1, tm + 1, tr, i, val);
  }
  tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
long long int query(long long int id, long long int tl, long long int tr,
                    long long int l, long long int r) {
  if (tl > tr or tr < l or tl > r) {
    return 0;
  }
  if (l <= tl and tr <= r) {
    return tree[id];
  }
  long long int tm = (tl + tr) / 2;
  if (r <= tm) {
    return query(id * 2, tl, tm, l, r);
  } else if (l > tm) {
    return query(id * 2 + 1, tm + 1, tr, l, r);
  } else {
    long long int q1 = query(id * 2, tl, tm, l, r);
    long long int q2 = query(id * 2 + 1, tm + 1, tr, l, r);
    return q1 + q2;
  }
}
void merge_it(vector<pair<long long int, long long int>> &v) {
  sort(v.begin(), v.end());
  long long int k = 1;
  for (long long int i = 1; i < (long long int)v.size(); ++i) {
    if (v[i].first > v[k - 1].second) {
      v[k++] = v[i];
      continue;
    }
    v[i].second = max(v[i].second, v[k - 1].second);
  }
  v.resize(k);
}
void merge(map<long long int, vector<pair<long long int, long long int>>> &g) {
  for (auto &x : g) {
    merge_it(x.second);
  }
}
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 0, x1, y1, x2, y2; i < n; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    h.push_back(y1);
    h.push_back(y2);
    if (x1 == x2) {
      if (y1 > y2) swap(y1, y2);
      gx[x1].push_back({y1, y2});
    } else {
      if (x1 > x2) swap(x1, x2);
      gy[y1].push_back({x1, x2});
    }
  }
  merge(gx);
  merge(gy);
  sort(h.begin(), h.end());
  h.erase(unique(h.begin(), h.end()), h.end());
  map<long long int, long long int> posh;
  for (long long int i = 0; i < (long long int)h.size(); ++i) {
    posh[h[i]] = i;
  }
  vector<pair<long long int, pair<long long int, long long int>>> v;
  long long int ans = 0;
  for (auto &x : gx) {
    long long int x1 = x.first;
    for (auto &y : x.second) {
      v.push_back({x1, {y.first, y.second}});
      ans += y.second - y.first + 1;
    }
  }
  const long long int MN = (long long int)1e9;
  for (auto &x : gy) {
    long long int yy = x.first;
    for (auto &y : x.second) {
      long long int x1 = y.first, x2 = y.second;
      v.push_back({x1, {-MN - 1, yy}});
      v.push_back({x2 + 1, {-MN - 2, yy}});
      ans += x2 - x1 + 1;
    }
  }
  sort(v.begin(), v.end());
  for (long long int i = 0; i < (long long int)v.size(); ++i) {
    long long int x = v[i].first;
    long long int y1 = v[i].second.first, y2 = v[i].second.second;
    if (y1 == -MN - 1) {
      update(1, 0, (long long int)h.size() - 1, posh[y2], 1);
    } else if (y1 == -MN - 2) {
      update(1, 0, (long long int)h.size() - 1, posh[y2], -1);
    } else {
      ans -= query(1, 0, (long long int)h.size() - 1, posh[y1], posh[y2]);
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int T = 1;
  for (long long int i = 1; i <= T; ++i) {
    solve();
  }
  return 0;
}
