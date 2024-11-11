#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
  if (x < y) x = y;
}
mt19937 rnd(time(0));
vector<pair<int, int>> solve(vector<int> a) {
  int n = a.size();
  map<vector<int>, pair<int, int>> p;
  queue<vector<int>> q;
  q.push(a);
  p[a] = {1, 1};
  while (q.size()) {
    auto v = q.front();
    q.pop();
    for (int i = 0; i < v.size(); ++i) {
      for (int d = 1; i + 2 * d < v.size(); ++d) {
        v[i] ^= 1;
        v[i + d] ^= 1;
        v[i + 2 * d] ^= 1;
        if (!p.count(v)) {
          p[v] = {i, d};
          q.push(v);
        }
        v[i] ^= 1;
        v[i + d] ^= 1;
        v[i + 2 * d] ^= 1;
      }
    }
  }
  vector<pair<int, int>> ans;
  vector<int> rec(n, 0);
  if (!p.count(rec)) {
    return {{-1, -1}};
  }
  while (rec != a) {
    auto nw = p[rec];
    ans.push_back(nw);
    rec[nw.first] ^= 1;
    rec[nw.first + nw.second] ^= 1;
    rec[nw.first + 2 * nw.second] ^= 1;
  }
  return ans;
}
void imp(vector<int>& a, pair<int, int> gg) {
  a[gg.first] ^= 1, a[gg.first + gg.second] ^= 1,
      a[gg.first + 2 * gg.second] ^= 1;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.precision(20), cout.setf(ios::fixed);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  if (n <= 11) {
    auto ww = solve(a);
    if (ww.size() && ww[0].first == -1) {
      cout << "NO";
      return 0;
    }
    cout << "YES\n";
    cout << ww.size() << '\n';
    for (auto i : ww) {
      cout << i.first + 1 << ' ' << i.first + 1 + i.second << ' '
           << i.first + 1 + i.second * 2 << '\n';
    }
    return 0;
  }
  vector<pair<int, int>> ans;
  while (a.size() >= 14) {
    if (a.back() == 1 && a[a.size() - 2] == 1 && a[a.size() - 3] == 0) {
      bool fn = 0;
      for (int fs = a.size() - 11; fs < a.size(); ++fs) {
        for (int d1 = 1; d1 * 2 + fs < a.size(); ++d1) {
          for (int ss = a.size() - 11; ss < a.size(); ++ss) {
            for (int d2 = 1; d2 * 2 + ss < a.size(); ++d2) {
              imp(a, {fs, d1});
              imp(a, {ss, d2});
              if (count(a.end() - 6, a.end(), 0) == 6) {
                fn = 1;
                ans.push_back({fs, d1});
                ans.push_back({ss, d2});
                break;
              }
              imp(a, {fs, d1});
              imp(a, {ss, d2});
            }
            if (fn) break;
          }
          if (fn) break;
        }
        if (fn) break;
      }
      for (int j = 0; j < 6; ++j) a.pop_back();
    } else {
      vector<int> nw = {a[a.size() - 3], a[a.size() - 2], a.back()};
      if (nw == vector<int>{0, 0, 0}) {
      } else if (nw == vector<int>{0, 0, 1}) {
        ans.push_back({a.size() - 7, 3});
        imp(a, ans.back());
      } else if (nw == vector<int>{0, 1, 0}) {
        ans.push_back({a.size() - 6, 2});
        imp(a, ans.back());
      } else if (nw == vector<int>{1, 1, 0}) {
        ans.push_back({a.size() - 4, 1});
        imp(a, ans.back());
      } else if (nw == vector<int>{1, 0, 1}) {
        ans.push_back({a.size() - 5, 2});
        imp(a, ans.back());
      } else if (nw == vector<int>{1, 1, 1}) {
        ans.push_back({a.size() - 3, 1});
        imp(a, ans.back());
      } else if (nw == vector<int>{1, 0, 0}) {
        ans.push_back({a.size() - 5, 1});
        imp(a, ans.back());
      }
      for (int j = 0; j < 3; ++j) a.pop_back();
    }
  }
  auto tnw = solve(a);
  for (auto j : tnw) ans.push_back(j);
  cout << "YES\n";
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i.first + 1 << ' ' << i.first + 1 + i.second << ' '
         << i.first + 1 + i.second * 2 << '\n';
  }
}
