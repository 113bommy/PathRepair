#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
struct info {
  int v, pa, c;
  bool operator<(info a) const {
    if (v == a.v && c == a.c) return pa < a.pa;
    if (v == a.v) return c > a.c;
    return v > a.v;
  }
};
set<info> sp, si;
vector<info> ans;
int n;
pair<int, int> a[maxn], b[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int tmp;
  for (int i = 1; i <= n; ++i) {
    cin >> tmp;
    a[i] = {tmp, i};
  }
  for (int i = 1; i <= n; ++i) {
    cin >> tmp;
    b[i] = {tmp, i};
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  long long tol = 0;
  for (int i = 1; i <= n; ++i) {
    int tmp = a[i].first - b[i].first;
    tol += tmp;
    if (tmp < 0) {
      si.insert({a[i].first, a[i].second, -tmp});
    } else if (tmp > 0) {
      sp.insert({a[i].first, a[i].second, tmp});
    }
  }
  if (tol) {
    cout << "NO" << endl;
    return 0;
  }
  while (si.size() && sp.size()) {
    info ta = *sp.begin();
    info tb = *si.begin();
    if (ta.v - tb.v > 1) {
      si.erase(tb);
      sp.erase(ta);
      if (ta.c > tb.c) {
        ans.push_back({tb.pa, ta.pa, tb.c});
        ta.c -= tb.c;
        sp.insert(ta);
      } else if (ta.c < tb.c) {
        ans.push_back({tb.pa, ta.pa, ta.c});
        tb.c -= ta.c;
        si.insert(tb);
      } else {
        ans.push_back({tb.pa, ta.pa, ta.c});
      }
    } else {
      break;
    }
  }
  if (si.size() || sp.size() || ans.size() > 5 * n) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto i : ans) {
      cout << i.v << " " << i.pa << " " << i.c << endl;
    }
  }
  return 0;
}
