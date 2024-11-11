#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 510000;
int n;
int tp;
int xx[N];
int ans[N];
vector<pair<int, int>> vv;
set<pair<int, int>> ss;
int a[N];
int b[N];
int cur;
void st(int x) {
  b[x] = 1;
  ans[x] = cur;
}
void add(int x) {
  auto it = ss.emplace(x, 1).first;
  if (it != ss.begin()) {
    auto pr = *prev(it);
    if (pr.second == 0) {
      int m = (pr.first + x) / 2;
      for (int i = m; i < x && !b[i]; ++i) {
        st(i);
      }
    } else {
      for (int i = x - 1; i >= pr.first && !b[i]; --i) {
        st(i);
      }
    }
  }
  if (next(it) != ss.end()) {
    auto pr = *next(it);
    if (pr.second == 0) {
      int m = (pr.first + x - 1) / 2;
      for (int i = m; i >= x && !b[i]; --i) {
        st(i);
      }
    } else {
      for (int i = x; i < pr.first && !b[i]; ++i) {
        st(i);
      }
    }
  }
}
const int INF = 1e9;
int gans = 0;
void upd(int x) {
  auto it = ss.lower_bound(make_pair(x, 0));
  if (it == ss.begin() || it == ss.end()) {
    return;
  }
  gans = max(gans, ((it->first - prev(it)->first) - 1) / 2);
}
void del(int x) {
  auto it = ss.find({x, 0});
  pair<int, int> l, r;
  if (it != ss.begin()) {
    l = *prev(it);
  } else {
    l = {-INF, 0};
  }
  if (next(it) != ss.end()) {
    r = *next(it);
  } else {
    r = {INF, 0};
  }
  ss.erase(it);
  if (l.second == 0 && r.second == 0) {
    return;
  }
  if (l.second == 0 && r.second == 1) {
    int m = (l.first + r.first) / 2;
    m = max(m, 0);
    for (int i = m; i < r.first && !b[i]; ++i) {
      st(i);
    }
  }
  if (l.second == 1 && r.second == 0) {
    int m = (l.first + r.first - 1) / 2;
    m = min(m, n - 1);
    for (int i = m; i >= l.first && !b[i]; --i) {
      st(i);
    }
  }
  if (l.second == 1 && r.second == 1) {
    for (int i = x; i < r.first && !b[i]; ++i) {
      st(i);
    }
    for (int i = x - 1; i >= l.first && !b[i]; --i) {
      st(i);
    }
  }
}
vector<int> ququ;
void qu(int x) { ququ.push_back(x); }
void clear() {
  while (!ququ.empty()) {
    int x = ququ.back();
    upd(x);
    ququ.pop_back();
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> xx[i];
    vv.emplace_back(xx[i], i);
  }
  tp = xx[0];
  sort((vv).begin(), (vv).end());
  for (int i = 0; i <= n; ++i) {
    ss.emplace(i, 0);
  }
  for (int i = 0; i < (int)vv.size(); ++i) {
    int x = vv[i].second;
    cur = vv[i].first;
    a[x] = 1;
    if (x == 0 || a[x - 1] == 0) {
      del(x);
    }
    if (x == 0 || a[x - 1] == 1) {
      add(x);
    }
    if (x == n - 1 || a[x + 1] == 0) {
      del(x + 1);
    }
    if (x == n - 1 || a[x + 1] == 1) {
      add(x + 1);
    }
    qu(x);
    qu(x + 1);
    qu(x + 2);
    if (i + 1 == vv.size() || vv[i + 1].first != vv[i].first) {
      clear();
    }
    a[x] = 1;
  }
  cout << gans << "\n";
  if (tp == 1) {
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
