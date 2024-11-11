#include <bits/stdc++.h>
using namespace std;
class A {
 public:
  void solve() {
    int t, n;
    cin >> t;
    while (t--) {
      cin >> n;
      bool ok = false;
      for (int i = 0; 3 * i <= n; i++) {
        for (int j = 0; j * 5 + i * 3 <= n; j++) {
          int k = n - i * 3 - j * 5;
          if (k >= 0 && k % 7 == 0) {
            ok = true;
            cout << i << " " << j << " " << k / 7 << endl;
            break;
          }
        }
        if (ok) break;
      }
      if (!ok) cout << -1 << endl;
    }
  }
};
class B {
 public:
  void solve() {
    int t;
    cin >> t;
    while (t--) {
      int n, k;
      cin >> n >> k;
      vector<long long> a(n, 0);
      for (int i = 0; i < n; i++) {
        cin >> a[i];
      }
      sort(a.begin(), a.end());
      long long high = a.back();
      for (int i = n - 2; i >= 0 && k > 0; k--, i--) {
        if (a[i] == 0) break;
        high += a[i];
      }
      cout << high << endl;
    }
  }
};
class C {
 public:
  void solve() {
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<pair<int, int> > res;
      cout << 2 << endl;
      if (n == 2) {
        cout << 1 << ' ' << 2 << endl;
        continue;
      }
      res.emplace_back(n, n - 2);
      int cur = n - 1;
      res.emplace_back(cur, cur);
      while (cur > 2) {
        res.emplace_back(cur, cur - 2);
        cur = cur - 1;
      }
      for (auto r : res) cout << r.first << " " << r.second << endl;
    }
  }
};
struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    if (a.first > 2 && b.first > 2) return a.second > b.second;
    if (a.first > 2) return true;
    if (b.first > 2) return false;
    return a.second > b.second;
  }
};
class D {
 public:
  void solve() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
      int n;
      cin >> n;
      string s;
      cin >> s;
      set<pair<int, int>, cmp> cnt;
      vector<int> a;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] == s[i - 1])
          sum++;
        else {
          a.push_back(sum);
          sum = 1;
        }
      }
      a.push_back(sum);
      for (int i = 0; i < a.size(); i++) {
        cnt.emplace(a[i], i);
      }
      int res = 0;
      for (int i = 0; i < a.size(); i++) {
        cnt.erase(pair<int, int>{a[i], i});
        if (a[i] == 0) continue;
        res++;
        if (cnt.size() == 0) break;
        if (a[i] == 1) {
          auto mx = *cnt.rbegin();
          cnt.erase(mx);
          a[mx.second]--;
          if (a[mx.second] >= 1) {
            cnt.insert(pair<int, int>{a[mx.second], mx.second});
          }
        }
      }
      cout << res << endl;
    }
  }
};
class E {
 public:
  void solve() {}
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  D ans;
  ans.solve();
  return 0;
}
