#include <bits/stdc++.h>
using namespace std;
class A {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (sum[i] >= sum[n] - sum[i]) {
        cout << i << endl;
        return;
      }
    }
  }
};
class B {
 public:
  void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int res = 0;
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
      if (i == n || s[i] == '*') {
        int mi = cnt / 2, mx = cnt - cnt / 2;
        cnt = 0;
        int aa = min(mx, max(a, b));
        int bb = min(mi, min(a, b));
        res += aa + bb;
        int tempa = max(a, b) - aa;
        int tempb = min(a, b) - bb;
        a = tempa;
        b = tempb;
      } else
        cnt++;
    }
    cout << res << endl;
  }
};
class C {
 public:
  void solve() {
    long long n;
    cin >> n;
    long long res = 0x3f3f3f3f;
    vector<int> seq;
    long long k = n;
    while (k) seq.push_back(k % 10), k /= 10;
    auto check = [&seq](int k) {
      int i = 0;
      int cnt = 0;
      while (k) {
        int cur = k % 10;
        cnt++;
        k /= 10;
        while (i < seq.size() && seq[i] != cur) i++;
        if (i == seq.size()) return -1;
        i++;
      }
      return (int)seq.size() - cnt;
    };
    for (long long i = 1; i * i <= n; i++) {
      int ck = check(i * i);
      if (ck != -1) res = min(res, (long long)ck);
    }
    if (res == 0x3f3f3f3f)
      cout << -1 << endl;
    else
      cout << res << endl;
  }
};
class D {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), res(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<long long, priority_queue<int, vector<int>, greater<int>>> cnt;
    for (int i = 0; i < n; i++) {
      cnt[a[i]].push(i);
    }
    while (!cnt.empty()) {
      auto u = cnt.begin()->first;
      if (cnt[u].size() == 0)
        cnt.erase(u);
      else if (cnt[u].size() == 1) {
        res[cnt[u].top()] = u;
        cnt.erase(u);
      } else {
        int x = cnt[u].top();
        cnt[u].pop();
        int y = cnt[u].top();
        cnt[u].pop();
        cnt[u * 2].push(y);
      }
    }
    vector<long long> ans;
    for (long long i : res)
      if (i != 0) ans.push_back(i);
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';
    cout << endl;
  }
};
class E {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> pos;
    vector<pair<long long, char>> a(n + 2);
    long long pre = 0;
    vector<long long> R, B;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
      if (a[i].second == 'P')
        pos.push_back(a[i].first);
      else if (a[i].second == 'R') {
        if (!R.empty()) pre += a[i].first - R.back();
        R.push_back(a[i].first);
      } else {
        if (!B.empty()) pre += a[i].first - B.back();
        B.push_back(a[i].first);
      }
    }
    if (pos.empty()) {
      cout << pre << endl;
      return;
    }
    long long res = 0;
    if (!R.empty() && R.front() <= pos[0]) res += pos[0] - R.front();
    if (!B.empty() && B.front() <= pos[0]) res += pos[0] - B.front();
    if (!R.empty() && R.back() >= pos.back()) res += R.back() - pos.back();
    if (!B.empty() && B.back() >= pos.back()) res += B.back() - pos.back();
    int r = 0, b = 0;
    for (int i = 0; i + 1 < pos.size(); i++) {
      long long start = pos[i], ends = pos[i + 1];
      vector<long long> ta, tb;
      ta.clear();
      tb.clear();
      ta.push_back(start);
      tb.push_back(start);
      while (r < R.size() && R[r] <= ends) {
        if (R[r] >= start) ta.push_back(R[r]);
        r++;
      }
      while (b < B.size() && B[b] <= ends) {
        if (B[b] >= start) tb.push_back(B[b]);
        b++;
      }
      ta.push_back(ends);
      tb.push_back(ends);
      long long diffa = 0, diffb = 0, len = ends - start;
      for (int k = 1; k < ta.size(); k++) diffa = max(diffa, ta[k] - ta[k - 1]);
      for (int k = 1; k < tb.size(); k++) diffb = max(diffb, tb[k] - tb[k - 1]);
      long long cost = len;
      if (diffa != len) cost += len - diffa;
      if (diffb != len) cost += len - diffb;
      long long cur = len;
      if (R.size() > 0 && B.size() > 0) cur += len;
      res += min(cur, cost);
    }
    cout << res << endl;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  E ans;
  ans.solve();
  return 0;
}
