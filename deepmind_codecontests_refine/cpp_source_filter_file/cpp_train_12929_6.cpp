#include <bits/stdc++.h>
using namespace std;
template <typename T>
void debug_out(T t) {
  cerr << t;
}
template <typename A, typename B>
void debug_out(pair<A, B> u) {
  cerr << "(" << u.first << " " << u.second << ")";
}
template <typename T>
void debug_out(vector<T> t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << ", ";
  }
}
template <typename T>
void debug_out(vector<vector<T>> t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << endl;
  }
}
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i] - 2;
  }
  int pos = max_element(a.begin(), a.end()) - a.begin();
  int res = 2 * a[pos] - 2 - sum;
  if ((res % 2 == 0 && res >= 4) || (res % 2 != 0 && res >= 3)) {
    cout << a[pos] << endl;
    int cur = 1;
    for (int i = 0; i < n; i++) {
      if (i == pos) {
        for (int j = 0; j < a[pos]; j++) cout << j + 1 << " ";
      } else {
        cout << 1 << " ";
        for (int j = 0; j < a[i] - 1; j++) cout << cur + j + 1 << " ";
        cur += a[i] - 1;
      }
      cout << endl;
    }
  } else {
    if (res % 2 == 0)
      res = 4;
    else
      res = 3;
    int s = a[pos];
    sum -= a[pos] - 2;
    vector<vector<int>> ans(n);
    ans[pos].resize(s);
    iota(ans[pos].begin(), ans[pos].end(), 0);
    vector<int> cur = ans[pos];
    set<pair<int, int>> edges;
    auto handle = [&](int i) {
      int ss = ans[i].size();
      for (int j = 0; j < ss; j++) {
        edges.insert(make_pair(ans[i][j], ans[i][(j + 1) % ss]));
        edges.insert(make_pair(ans[i][(j + 1) % ss], ans[i][j]));
      }
    };
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    stable_sort(id.begin(), id.end(),
                [&](int x, int y) { return a[x] > a[y]; });
    for (int ii = 0; ii < n; ii++) {
      int i = id[ii];
      if (i == pos) continue;
      int sz = cur.size();
      int y = max(0, a[i] - 1 - (sum + res - sz) / 2);
      int x = a[i] - y;
      if (x == 1) {
        for (int j : cur) assert(j < s);
        auto get = [&](int j, int p) {
          for (int st = p; st < p + a[j]; st++) ans[j].push_back(cur[st]);
          vector<int> add;
          for (int st = p + a[j] - 1; st < (int)cur.size(); st++)
            add.push_back(cur[st]);
          cur.resize(p + 1);
          for (int st : add) cur.push_back(st);
          handle(j);
        };
        for (int j = ii; j < n; j++) {
          for (int x = cur.size() - 2; x > -1; x--) {
            if (edges.find(make_pair(cur[x], cur[x - a[id[j]] + 1])) ==
                edges.end()) {
              get(id[j], x - a[id[j]] + 1);
              break;
            }
          }
        }
        break;
      }
      int p = cur.back();
      for (int j = sz - 1; j > sz - y - 2; j--) ans[i].push_back(cur[j]);
      cur.resize(sz - y);
      for (int j = 0; j < x - 1; j++) {
        ans[i].push_back(s);
        cur.push_back(s);
        s++;
      }
      handle(i);
      cur.push_back(p);
      sum -= a[i] - 2;
    }
    cout << s << endl;
    for (int i = 0; i < n; i++) {
      for (int j : ans[i]) {
        assert(j < s);
        cout << j + 1 << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
