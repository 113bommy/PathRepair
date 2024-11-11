#include <bits/stdc++.h>
using namespace std;
class p1328D {
 public:
  void solve() {
    int q;
    cin >> q;
    while (q--) {
      int n;
      cin >> n;
      vector<int> t(n);
      for (int i = 0; i < n; i++) cin >> t[i];
      int sum = 1;
      for (int i = 1; i < n; i++) {
        if (t[i] == t[i - 1]) sum++;
      }
      if (sum == n) {
        cout << 1 << endl;
        for (int i = 0; i < n; i++) cout << 1 << " ";
        cout << endl;
      } else if (n % 2 == 0 || t.back() == t.front()) {
        cout << 2 << endl;
        for (int i = 0; i < n; i++) cout << i % 2 + 1 << " ";
        cout << endl;
      } else if (sum > 1) {
        cout << 2 << endl;
        bool can = true;
        for (int i = 0; i < n; i++) {
          if (can && i > 0 && t[i] == t[i - 1]) {
            cout << (i - 1) % 2 + 1 << " ";
            can = false;
          } else if (!can)
            cout << (i - 1) % 2 + 1 << ' ';
          else
            cout << i % 2 + 1 << ' ';
        }
        cout << endl;
      } else {
        cout << 3 << endl;
        for (int i = 0; i < n - 1; i++) cout << i % 2 + 1 << " ";
        cout << 3 << endl;
      }
    }
  }
};
class p1327E {
 public:
  long long MOD = 998244353;
  long long fastpow(long long x, long long n) {
    if (n == 0) return 1ll;
    if (n == 1) return x;
    long long temp = fastpow(x, n / 2);
    if (n % 2 == 0)
      return (temp * temp) % MOD;
    else
      return (((x * temp) % MOD) * temp) % MOD;
  }
  void solve() {
    int n;
    cin >> n;
    if (n < 2) {
      cout << 10 << endl;
      return;
    }
    int maxn = 2e5 + 10;
    vector<long long> dp(maxn, 1);
    for (int i = 1; i <= maxn; i++) {
      dp[i] = (dp[i - 1] * 10) % MOD;
    }
    for (int i = 1; i < n; i++) {
      long long res = 2 * 10 * 9 * dp[n - i - 1] % MOD;
      res += (n - i - 1) * 10 * 9 * 9 * dp[n - i - 2] % MOD;
      cout << res % MOD << " ";
    }
    cout << 10 << endl;
  }
};
class p161D {
 public:
  long long res, k, n;
  vector<vector<int>> e;
  vector<vector<long long>> dp;
  void dfs(int cur, int fa) {
    dp[cur][0] = 1;
    for (int c : e[cur]) {
      if (c == fa) continue;
      dfs(c, cur);
      for (int i = 1; i <= k; i++) {
        dp[cur][i] += dp[c][i - 1];
      }
    }
    res += dp[cur][k];
    long long temp = 0;
    for (int c : e[cur]) {
      if (c == fa) continue;
      for (int i = 0; k - 2 - i >= 0; i++) {
        temp += dp[c][i] * (dp[cur][k - i - 1] - dp[c][k - i - 2]);
      }
    }
    res += temp / 2;
  }
  void solve() {
    cin >> n >> k;
    e = vector<vector<int>>(n + 1);
    dp = vector<vector<long long>>(n + 1, vector<long long>(k + 1, 0));
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      e[a].push_back(b);
      e[b].push_back(a);
    }
    res = 0;
    dfs(1, 0);
    cout << res << endl;
  }
};
class p1437C {
 public:
  void solve() {
    int q;
    cin >> q;
    while (q--) {
      int n;
      cin >> n;
      vector<int> t(n);
      for (int i = 0; i < n; i++) cin >> t[i];
      sort(t.begin(), t.end());
      vector<vector<int>> dp(2 * n + 1, vector<int>(n + 1, 0x3f3f3f3f));
      dp[0][0] = 0;
      int res = 0x3f3f3f3f;
      for (int k = 1; k <= 2 * n; k++) {
        for (int i = 1; i <= n; i++) {
          for (int pre = 0; pre <= k - 1; pre++) {
            dp[k][i] = min(dp[k][i], dp[pre][i - 1] + abs(t[i - 1] - k));
          }
        }
        res = min(res, dp[k][n]);
      }
      cout << res << endl;
    }
  }
};
class p1038D {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      cout << a[0] << endl;
      return;
    }
    long long ans = 0, minval = 0x3f3f3f3f;
    bool pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
      ans += abs(a[i]);
      pos |= (a[i] >= 0);
      neg |= (a[i] <= 0);
      minval = min(minval, abs(a[i]));
    }
    if (pos && neg)
      cout << ans << endl;
    else
      cout << ans - 2 * minval << endl;
  }
};
class p1286A {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    unordered_set<int> cnt;
    for (int i = 1; i <= n; i++) cnt.insert(i);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      if (p[i] != 0) cnt.erase(p[i]);
    }
    int odd = 0, even = 0;
    for (int i : cnt)
      if (i % 2)
        odd++;
      else
        even++;
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0x3f3f3f3f)));
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
      int cur = p[i - 1] % 2;
      for (int j = 0; j <= min(odd, i); j++) {
        if (p[i - 1] != 0) {
          dp[i][j][cur] =
              min(dp[i - 1][j][0] + (0 ^ cur), dp[i - 1][j][1] + (1 ^ cur));
        } else {
          if (j >= 1) {
            dp[i][j][1] = min(
                dp[i][j][1], min(dp[i - 1][j - 1][0] + 1, dp[i - 1][j - 1][1]));
          }
          dp[i][j][0] =
              min(dp[i][j][0], min(dp[i - 1][j][0], dp[i - 1][j][1] + 1));
        }
      }
    }
    cout << min(dp[n][odd][0], dp[n][odd][1]) << endl;
  }
};
class p580D {
 public:
  void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<long long>> cost(n + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> dp(1 << n, vector<long long>(n + 1, 0));
    for (int i = 0; i < k; i++) {
      long long x, y, c;
      cin >> x >> y >> c;
      cost[x][y] = c;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      dp[1 << (i - 1)][i] = a[i];
    }
    for (int i = 1; i < (1 << n); i++) {
      int cnt = bitset<32>(i).count();
      for (int j = 1; j <= n; j++) {
        if ((i & (1 << (j - 1))) != 0) {
          int pre = i ^ (1 << (j - 1));
          for (int k = 1; k <= n; k++) {
            if ((pre & (1 << (k - 1))) == 0) continue;
            dp[i][j] = max(dp[i][j], dp[pre][k] + cost[k][j] + a[j]);
          }
          if (cnt == m) ans = max(ans, dp[i][j]);
        }
      }
    }
    cout << ans << endl;
  }
};
class p1335E2 {
 public:
  void solve() {
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<int> a(n + 1);
      for (int i = 1; i <= n; i++) cin >> a[i];
      vector<vector<int>> sum(n + 1, vector<int>(205, 0));
      vector<vector<int>> pos(205);
      int res = 0;
      for (int i = 1; i <= n; i++) {
        sum[i][a[i]]++;
        for (int j = 1; j <= 200; j++) {
          sum[i][j] += sum[i - 1][j];
          res = max(res, sum[i][j]);
        }
        pos[a[i]].push_back(i);
      }
      for (int i = 1; i <= 200; i++) {
        int len = pos[i].size();
        for (int k = 0; k < len - 1 - k; k++) {
          int l = pos[i][k], r = pos[i][len - 1 - k] - 1;
          int mid = 0;
          for (int j = 1; j <= 200; j++) {
            mid = max(mid, sum[r][j] - sum[l][j]);
          }
          res = max(res, 2 * (k + 1) + mid);
        }
      }
      cout << res << endl;
    }
  }
};
class p1221D {
 public:
  void solve() {
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<long long> a(n + 1), b(n + 1);
      a[0] = 0;
      for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
      vector<vector<long long>> dp(n + 1, vector<long long>(4, -1));
      dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
      long long res = LONG_LONG_MAX;
      for (long long i = 1; i <= n; i++) {
        for (long long j = 0; j <= 2; j++) {
          for (int k = 0; k <= 2; k++) {
            if (a[i] + j != a[i - 1] + k) {
              auto cur = j * b[i] + dp[i - 1][k];
              dp[i][j] = dp[i][j] == -1 ? cur : min(dp[i][j], cur);
            }
          }
          if (i == n) res = min(res, dp[i][j]);
        }
      }
      cout << res << endl;
    }
  }
};
class p543A {
 public:
  void solve() {
    int n, m, b, md;
    cin >> n >> m >> b >> md;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(m + 1, vector<int>(b + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int k = 0; k <= m; k++) {
        for (int j = 0; j <= b; j++) {
          if (j >= a[i] && k > 0)
            dp[k][j] = (dp[k][j] + dp[k - 1][j - a[i]]) % md;
        }
      }
    }
    long long res = 0;
    for (int i = 0; i <= b; i++) res = (res + dp[m][i]) % md;
    cout << res << endl;
  }
};
class p1142A {
 public:
  void solve() {
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) cin >> a[i];
      int left = a[0];
      bool ok = 1;
      int mx = 0;
      for (int i = 1; i < n; i++) {
        if (mx > a[i]) {
          ok = false;
          break;
        }
        a[i] -= mx;
        if (left >= a[i])
          left = a[i];
        else {
          mx += a[i] - left;
        }
      }
      if (ok)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
};
class p1244D {
 public:
  vector<int> node;
  vector<vector<int>> e;
  void dfs(int cur, int fa) {
    node.push_back(cur);
    for (int c : e[cur]) {
      if (c == fa) continue;
      dfs(c, cur);
    }
  }
  void solve() {
    int n;
    cin >> n;
    vector<vector<long long>> cost(n + 1, vector<long long>(3, 0));
    for (int j = 0; j < 3; j++) {
      for (int i = 1; i <= n; i++) {
        cin >> cost[i][j];
      }
    }
    e = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
      if (e[u].size() > 2 || e[v].size() > 2) {
        cout << -1 << endl;
        return;
      }
    }
    int start = -1;
    for (int i = 1; i <= n; i++) {
      if (e[i].size() == 1) {
        start = i;
        break;
      }
    }
    dfs(start, -1);
    long long res = 4e18;
    int x = -1, y = -1;
    for (int i = 0; i < 3; i++) {
      for (int k = 0; k < 3; k++) {
        if (k == i) continue;
        long long temp = 0;
        temp += cost[node[0]][i] + cost[node[1]][k];
        int a = i, b = k;
        for (int j = 2; j < node.size(); j++) {
          for (int l = 0; l < 3; l++) {
            if (l == a || l == b) continue;
            temp += cost[node[j]][l];
            a = b;
            b = l;
            break;
          }
        }
        if (temp < res) {
          res = temp;
          x = i;
          y = k;
        }
      }
    }
    cout << res << endl;
    vector<int> ans(n + 1, 0);
    ans[node[0]] = x;
    ans[node[1]] = y;
    for (int i = 2; i < node.size(); i++) {
      for (int l = 0; l < 3; l++) {
        if (l == x || l == y) continue;
        ans[node[i]] = l;
        x = y;
        y = l;
        break;
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] + 1 << " ";
    cout << endl;
  }
};
class p519D {
 public:
  void solve() {
    vector<long long> cnt(26, 0);
    for (int i = 0; i < 26; i++) cin >> cnt[i];
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + cnt[s[i - 1] - 'a'];
    }
    long long res = 0;
    unordered_map<long long, long long> mp[26];
    for (int i = 1; i <= n; i++) {
      int cur = s[i - 1] - 'a';
      res += mp[cur][sum[i] - cnt[cur]];
      mp[cur][sum[i]]++;
    }
    cout << res << endl;
  }
};
class p1096D {
 public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    unordered_map<char, int> cnt;
    cnt['h'] = 0;
    cnt['a'] = 1;
    cnt['r'] = 2;
    cnt['d'] = 3;
    vector<long long> dp(4, 0);
    for (int i = 0; i < n; i++) {
      if (!cnt.count(s[i])) continue;
      if (s[i] == 'h')
        dp[0] += a[i];
      else
        dp[cnt[s[i]]] = min(dp[cnt[s[i]] - 1], dp[cnt[s[i]]] + a[i]);
    }
    cout << dp[3] << endl;
  }
};
class p1296E1 {
 public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res(n);
    res[0] = 0;
    char first = s[0];
    char second = 'a' - 1;
    for (int i = 1; i < n; i++) {
      if (s[i] >= first) {
        res[i] = 0;
        first = s[i];
      } else {
        if (s[i] >= second) {
          res[i] = 1;
          second = s[i];
        } else {
          cout << "NO" << endl;
          return;
        }
      }
    }
    cout << "YES" << endl;
    for (int i : res) cout << i;
    cout << endl;
  }
};
class p1296E2 {
 public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(26, 0);
    int res = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int d = 1;
      for (int j = s[i] - 'a' + 1; j < 26; j++) {
        d = max(d, dp[j] + 1);
      }
      dp[s[i] - 'a'] = d;
      ans.emplace_back(d);
    }
    for (int i = 0; i < 26; i++) res = max(res, dp[i]);
    cout << res << endl;
    for (auto c : ans) cout << c << ' ';
    cout << endl;
  }
};
class D {
 public:
  void solve() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
      int n, q;
      cin >> n >> q;
      vector<long long> a(n);
      for (int i = 0; i < n; i++) cin >> a[i];
      sort(a.begin(), a.end());
      vector<long long> sum(n + 1, 0);
      for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
      unordered_set<long long> cnt;
      cnt.insert(sum[n]);
      queue<pair<long long, long long>> que;
      que.emplace(0, n - 1);
      while (!que.empty()) {
        auto u = que.front();
        que.pop();
        if (u.first > u.second) continue;
        auto l = a[u.first], r = a[u.second];
        cnt.insert(sum[u.second + 1] - sum[u.first]);
        if (u.first == u.second) continue;
        long long mid = (l + r) / 2;
        auto it =
            upper_bound(a.begin() + u.first, a.begin() + u.second + 1, mid) -
            a.begin();
        if (it - 1 >= u.first && it - 1 != u.second)
          que.emplace(u.first, it - 1);
        if (it <= u.second && it != u.first) que.emplace(it, u.second);
      }
      while (q--) {
        long long s;
        cin >> s;
        if (cnt.count(s))
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
    }
  }
};
class p1462F {
 public:
  void solve() {
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<pair<long long, long long>> c;
      vector<int> a, b;
      c.clear();
      for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        a.push_back(l);
        b.push_back(r);
        c.emplace_back(l, r);
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      int res = n;
      for (int i = 0; i < n; i++) {
        auto leftcnt = lower_bound(b.begin(), b.end(), c[i].first) - b.begin();
        auto rightcnt =
            upper_bound(a.begin(), a.end(), c[i].second) - a.begin();
        res = min(res, (int)(leftcnt + n - rightcnt));
      }
      cout << res << endl;
    }
  }
};
class p1324F {
 public:
  vector<int> a;
  vector<int> dp;
  int n;
  vector<vector<int>> e;
  vector<int> fa;
  int dfs(int cur, int f) {
    dp[cur] = a[cur];
    for (int child : e[cur]) {
      if (child == f) continue;
      int next = dfs(child, cur);
      dp[cur] += max(0, next);
    }
    return dp[cur];
  }
  void dfs2(int cur, int fa) {
    dp[cur] = max(dp[cur], dp[cur] + max(0, dp[fa] - max(0, dp[cur])));
    for (int c : e[cur]) {
      if (c == fa) continue;
      dfs2(c, cur);
    }
  }
  void solve() {
    cin >> n;
    a = vector<int>(n + 1);
    e = vector<vector<int>>(n + 1);
    dp = vector<int>(n + 1, 0);
    fa = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == 0) a[i] = -1;
    }
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
      cout << dp[i] << " ";
    }
    cout << endl;
  }
};
class p1446B {
 public:
  void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int res = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
        }
        dp[i][j] = max(dp[i][j], max(dp[i - 1][j] - 1, dp[i][j - 1] - 1));
        res = max(res, dp[i][j]);
      }
    }
    cout << res << endl;
  }
};
class p1283E {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    int maxn = 200005;
    int ans1 = 0, ans2 = 0;
    unordered_map<int, int> cnt;
    for (int i : x) cnt[i]++;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] > 0) {
        ans1++;
        i += 2;
      }
    }
    for (int i = 1; i <= n + 1; i++) {
      if (cnt[i - 1] == 0 && cnt[i] > 0) {
        cnt[i - 1]++;
        cnt[i]--;
      }
      if (cnt[i] > 1) {
        cnt[i]--;
        cnt[i + 1]++;
      }
    }
    for (int i = 0; i <= n + 1; i++) {
      if (cnt[i] > 0) ans2++;
    }
    printf("%d %d\n", ans1, ans2);
  }
};
class p148D {
 public:
  vector<vector<vector<double>>> dp;
  double dfs(int w, int b, int cur) {
    if (dp[w][b][cur] >= 0.0) return dp[w][b][cur];
    if (w == 0) {
      if (cur == 0)
        dp[w][b][cur] = 0.0;
      else
        dp[w][b][cur] = 1.0;
      return dp[w][b][cur];
    }
    if (b == 0) {
      dp[w][b][cur] = 1.0;
      return 1.0;
    }
    dp[w][b][cur] = 1.0 * w / (w + b);
    if (cur == 0) {
      dp[w][b][cur] += (1.0 - dfs(w, b - 1, 1 - cur)) * (1.0 * b / (w + b));
    } else {
      dp[w][b][cur] += (1.0 - dfs(w - 1, b - 1, 1 - cur)) *
                       (1.0 * b / (w + b)) * (1.0 * w / (w + b - 1));
      if (b >= 2) {
        dp[w][b][cur] += (1.0 - dfs(w, b - 2, 1 - cur)) * (1.0 * b / (w + b)) *
                         (1.0 * (b - 1) / (w + b - 1));
      }
    }
    return dp[w][b][cur];
  }
  void solve() {
    int w, b;
    cin >> w >> b;
    dp = vector<vector<vector<double>>>(
        w + 1, vector<vector<double>>(b + 1, vector<double>(2, -1)));
    double res = dfs(w, b, 0);
    printf("%.9lf\n", res);
  }
};
class p95B {
 public:
  string ans, s;
  bool dfs(int id, int sum4, int sum7, bool ok) {
    if (id >= s.size()) return 1;
    if (ok) {
      ans.append(sum4, '4');
      ans.append(sum7, '7');
      return 1;
    }
    if (s[id] <= '4' && sum4) {
      ans.push_back('4');
      if (dfs(id + 1, sum4 - 1, sum7, s[id] < '4')) return true;
      ans.pop_back();
    }
    if (s[id] <= '7' && sum7) {
      ans.push_back('7');
      if (dfs(id + 1, sum4, sum7 - 1, s[id] < '7')) return 1;
      ans.pop_back();
    }
    return 0;
  }
  void solve() {
    cin >> s;
    ans.clear();
    s.clear();
    s.append(100000, '4');
    cout << s << endl;
    int n = s.size();
    if (n % 2 || !dfs(0, n / 2, n / 2, 0)) {
      ans.append((n + 2) / 2, '4');
      ans.append((n + 2) / 2, '7');
      cout << ans << endl;
    } else
      cout << ans << endl;
  }
};
class p182E {
 public:
  void solve() {
    int n, h;
    cin >> n >> h;
    vector<vector<vector<int>>> dp(
        h + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
    for (int i = 0; i < n; i++) dp[0][i][0] = dp[0][i][1] = 1;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    long long res = 0;
    for (int i = 1; i <= h; i++) {
      for (int j = 0; j < n; j++) {
        int l = a[j].first, w = a[j].second;
        if (i == l) dp[i][j][0] = (dp[i][j][0] + 1) % 1000000007;
        if (i == w && l != w) dp[i][j][1] = (dp[i][j][1] + 1) % 1000000007;
        for (int k = 0; k < n; k++) {
          if (k == j) continue;
          int pl = a[k].first, pw = a[k].second;
          if (i > l) {
            dp[i][j][0] =
                (dp[i][j][0] + dp[i - l][k][0] * (l == pw)) % 1000000007;
            dp[i][j][0] =
                (dp[i][j][0] + dp[i - l][k][1] * (l == pl)) % 1000000007;
          }
          if (i > w && l != w) {
            dp[i][j][1] =
                (dp[i][j][1] + dp[i - w][k][0] * (w == pw)) % 1000000007;
            dp[i][j][1] =
                (dp[i][j][1] + dp[i - w][k][1] * (w == pl)) % 1000000007;
          }
        }
        if (i == h) res = (res + dp[i][j][0] + dp[i][j][1]) % 1000000007;
      }
    }
    cout << res << endl;
  }
};
class p180E {
 public:
  void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int, vector<int>> cnt;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x].push_back(i);
    }
    int res = 0;
    for (auto it : cnt) {
      auto v = it.second;
      int sz = v.size();
      deque<int> q;
      for (int r = 0; r < sz; r++) {
        q.push_back(v[r]);
        while (!q.empty() && q.back() - q.front() + 1 - q.size() > k)
          q.pop_front();
        res = max(res, (int)q.size());
      }
    }
    cout << res << endl;
  }
};
class p30C {
 public:
  struct node {
    long long x, y, t;
    double p;
    node(long long xx, long long yy, long long tt, double pp)
        : x(xx), y(yy), t(tt), p(pp){};
    node(){};
    bool operator<(const node &rhs) const { return t < rhs.t; }
  };
  void solve() {
    int n;
    cin >> n;
    vector<node> a;
    for (int i = 0; i < n; i++) {
      long long x, y, t;
      double p;
      cin >> x >> y >> t >> p;
      a.emplace_back(x, y, t, p);
    }
    sort(a.begin(), a.end());
    vector<double> dp(a.size() + 1, 0.0);
    double res = 0.0;
    for (int i = 0; i < n; i++) {
      dp[i] = a[i].p;
      for (int j = 0; j < i; j++) {
        long long dis = abs(a[i].x - a[j].x) * abs(a[i].x - a[j].x) +
                        abs(a[i].y - a[j].y) * abs(a[i].y - a[j].y);
        long long dt = (a[i].t - a[j].t) * (a[i].t - a[j].t);
        if (dis <= dt) dp[i] = max(dp[i], dp[j] + a[i].p);
      }
      res = max(res, dp[i]);
    }
    printf("%.7lf", res);
  }
};
class p49D {
 public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n, vector<int>(2, 0x3f3f3f3f));
    dp[0][0] = s[0] != '0';
    dp[0][1] = s[0] != '1';
    for (int i = 1; i < n; i++) {
      dp[i][0] = s[i] != '0';
      dp[i][1] = s[i] != '1';
      dp[i][0] += dp[i - 1][1];
      dp[i][1] += dp[i - 1][0];
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
  }
};
class p721C {
 public:
  void solve() {
    int n, m, T;
    cin >> n >> m >> T;
    vector<vector<pair<long long, long long>>> e(n + 1);
    vector<int> in(n + 1, 0);
    for (int i = 0; i < m; i++) {
      int u, v, t;
      cin >> u >> v >> t;
      e[u].emplace_back(v, t);
      in[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (!in[i]) q.push(i);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    dp[1][1] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &[v, w] : e[u]) {
        for (int j = 2; j <= n; j++) {
          if (dp[v][j] > dp[u][j - 1] + w) {
            dp[v][j] = dp[u][j - 1] + w;
            f[v][j] = u;
          }
        }
        in[v]--;
        if (!in[v]) q.push(v);
      }
    }
    int ans = -1;
    for (int j = n; j >= 1; j--) {
      if (dp[n][j] <= T) {
        ans = j;
        break;
      }
    }
    cout << ans << endl;
    vector<int> out;
    for (int i = n, j = ans; f[i][j] != 0; i = f[i][j], j--) out.push_back(i);
    out.push_back(1);
    reverse(out.begin(), out.end());
    for (int i : out) cout << i << " ";
    cout << endl;
  }
};
class p830A {
 public:
  void solve() {
    long long n, k, p;
    cin >> n >> k >> p;
    vector<long long> a(n + 1, 0);
    vector<long long> b(k + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1e18));
    for (int i = 0; i <= k; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        dp[i][j] = min(dp[i][j - 1],
                       max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(p - b[j])));
      }
    }
    cout << dp[n][k] << endl;
  }
};
class p983B {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      dp[i][i] = f[i][i] = a[i];
    }
    for (int i = n; i >= 1; i--) {
      for (int j = i + 1; j <= n; j++) {
        f[i][j] = f[i][j - 1] ^ f[i + 1][j];
        dp[i][j] = max(dp[i][j], f[i][j]);
        dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));
      }
    }
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << dp[l][r] << endl;
    }
  }
};
class p671A {
 public:
  struct node {
    long long id;
    double at, bt;
    node(int _id, double t, double a, double b)
        : id(_id), at(a - t), bt(b - t){};
  };
  void solve() {
    long long ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    int n;
    cin >> n;
    vector<node> bt1, bt2;
    auto distance = [](long long x1, long long y1, long long x2, long long y2) {
      long long dx = abs(x1 - x2);
      long long dy = abs(y1 - y2);
      return 1.0 * sqrt(dx * dx + dy * dy);
    };
    double res = 0.0;
    for (int i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      auto dt = distance(x, y, tx, ty);
      auto da = distance(x, y, ax, ay);
      auto db = distance(x, y, bx, by);
      res += 2.0 * dt;
      bt1.emplace_back(i, dt, da, db);
      bt2.emplace_back(i, dt, da, db);
    }
    sort(bt1.begin(), bt1.end(),
         [](const node &a, const node &b) { return a.at < b.at; });
    sort(bt2.begin(), bt2.end(),
         [](const node &a, const node &b) { return a.bt < b.bt; });
    int i = 0, j = 0;
    double temp = min(res + bt1[i].at, res + bt2[j].bt);
    if (bt1[i].id != bt2[j].id) {
      res += bt1[i].at;
      res += bt2[j].bt;
    } else {
      res += min(bt1[0].at + (bt2.size() > 1 ? bt2[1].bt : 0),
                 bt2[0].bt + (bt1.size() > 1 ? bt1[1].at : 0));
    }
    res = min(temp, res);
    printf("%.15f\n", res);
  }
};
class p274B {
 public:
  int n;
  vector<vector<int>> edge;
  vector<long long> v;
  pair<long long, long long> dfs(int cur, int fa) {
    long long now = v[cur];
    long long curp = 0, curg = 1e18;
    for (int i : edge[cur]) {
      if (i == fa) continue;
      auto next = dfs(i, cur);
      curp = max(next.first, curp);
      if (next.second != 0) curg = min(next.second, curg);
    }
    if (curg == 1e18) {
      curg = 0;
    }
    now += -curg - curp;
    if (now >= 0)
      curp += now;
    else
      curg += now;
    return {curp, curg};
  }
  void solve() {
    cin >> n;
    edge = vector<vector<int>>(n + 1);
    v = vector<long long>(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) cin >> v[i];
    pair<long long, long long> it = dfs(1, 0);
    cout << abs(it.first) + abs(it.second) << endl;
  }
};
class p933A {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> two(n + 2, 0), one(n + 1, 0);
    if (a.back() == 2) two[n]++;
    for (int i = n - 1; i >= 1; i--) {
      two[i] += two[i + 1];
      if (a[i] == 2) two[i]++;
    }
    for (int i = 1; i <= n; i++) {
      one[i] += one[i - 1];
      if (a[i] == 1) one[i]++;
    }
    int res = 0;
    for (int l = 1; l <= n; l++) {
      int s = 0, t = 0;
      for (int r = l; r <= n; r++) {
        if (a[r] == 1) {
          s = max(s, t) + 1;
        } else {
          t++;
        }
        res = max(res, one[l - 1] + two[r + 1] + max(s, t));
      }
    }
    cout << res << endl;
  }
};
class p527D {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(),
         [](const pair<long long, long long> &a,
            const pair<long long, long long> &b) {
           return a.first + a.second < b.first + b.second;
         });
    long long res = 1;
    int last = 0;
    for (int i = 1; i < n; i++) {
      if (v[i].first - v[i].second >= v[last].first + v[last].second) {
        res++;
        last = i;
      }
    }
    cout << res << endl;
  }
};
class p1083A {
 public:
  vector<vector<pair<long long, long long>>> edge;
  vector<long long> dp;
  long long ans = 0;
  vector<long long> w;
  void dfs(int u, int fa) {
    dp[u] = w[u];
    for (auto &[v, c] : edge[u]) {
      if (v == fa) continue;
      dfs(v, u);
      ans = max(ans, dp[u] + dp[v] - c);
      dp[u] = max(dp[u], w[u] + dp[v] - c);
    }
  }
  void solve() {
    int n;
    cin >> n;
    w = vector<long long>(n + 1);
    ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> w[i];
      ans = max(ans, w[i]);
    }
    edge = vector<vector<pair<long long, long long>>>(n + 1);
    dp = vector<long long>(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
      long long u, v, c;
      cin >> u >> v >> c;
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
    }
    dfs(1, 0);
    cout << ans << endl;
  }
};
class p909C {
 public:
  void solve() {
    int n;
    cin >> n;
    string s(n, ' ');
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<long long>> dp(n, vector<long long>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
      if (s[i - 1] == 'f') {
        for (int j = 0; j < n; j++) {
          dp[i][j + 1] = dp[i - 1][j];
        }
      } else {
        long long cur = 0;
        for (int k = n; k >= 0; k--) {
          cur = (cur + dp[i - 1][k]) % 1000000007;
          dp[i][k] = (dp[i][k] + cur) % 1000000007;
        }
      }
    }
    long long res = 0;
    for (int i = 0; i <= n; i++) res = (res + dp[n - 1][i]) % 1000000007;
    cout << res << endl;
  }
};
class p743D {
 public:
  int n;
  vector<long long> a;
  vector<vector<long long>> edge;
  vector<vector<long long>> dp;
  long long ans = 0;
  void dfs(int u, int fa) {
    dp[u][0] = a[u];
    dp[u][1] = -4e18;
    long long mx1 = -4e18, mx2 = -4e18;
    for (int v : edge[u]) {
      if (v == fa) continue;
      dfs(v, u);
      dp[u][0] += dp[v][0];
      if (dp[v][1] >= mx1) {
        mx2 = mx1;
        mx1 = dp[v][1];
      } else if (dp[v][1] >= mx2)
        mx2 = dp[v][1];
      dp[u][1] = max(dp[u][1], dp[v][1]);
    }
    if (mx1 != -4e18 && mx2 != -4e18) ans = max(ans, mx1 + mx2);
    dp[u][1] = max(dp[u][0], dp[u][1]);
  }
  void solve() {
    cin >> n;
    a = vector<long long>(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    edge = vector<vector<long long>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    if (n <= 2) {
      cout << "Impossible" << endl;
      return;
    }
    dp = vector<vector<long long>>(n + 1, vector<long long>(2, 0));
    ans = -4e18;
    dfs(1, 0);
    if (ans == -4e18)
      cout << "Impossible" << endl;
    else
      cout << ans << endl;
  }
};
class p869C {
 public:
  void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<vector<long long>> f(5005, vector<long long>(5005, 0));
    long long md = 998244353;
    f[0][0] = 1;
    for (int i = 1; i <= 5000; i++) {
      f[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % md;
      }
    }
    long long ans1 = 0, ans2 = 0, ans3 = 0;
    auto compute = [&f, &md](long long &ans, int a, int b) {
      long long cur = 1;
      for (long long k = 0; k <= min(a, b); k++, cur *= k, cur %= md) {
        ans += (((f[a][k] * f[b][k] + md) % md) * cur) % md;
        ans %= md;
      }
      return ans;
    };
    long long res = ((compute(ans1, a, b) * compute(ans2, b, c) % md) *
                     compute(ans3, a, c)) %
                    md;
    cout << (res + md) % md << endl;
  }
};
class p768C {
 public:
  void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    int freq[1024];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      freq[a[i]]++;
    }
    while (k--) {
      vector<int> tmp(1024, 0);
      for (int i = 0; i < 1024; i++) tmp[i] = freq[i];
      int pre = 0;
      for (int i = 0; i < 1024; i++) {
        if (tmp[i] <= 0) continue;
        int cnt = 0;
        if (pre == 0)
          cnt = (tmp[i] + 1) / 2;
        else
          cnt = (tmp[i]) / 2;
        freq[i] -= cnt;
        freq[i ^ x] += cnt;
        pre ^= tmp[i] & 1;
      }
    }
    int mi = 2048, mx = 0;
    for (int i = 0; i < 1024; i++) {
      if (freq[i] > 0) {
        mi = min(mi, i);
        mx = max(mx, i);
      }
    }
    cout << mx << " " << mi << endl;
  }
};
class p1107D {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    auto f = [](char c) {
      if (c <= '9')
        return c - '0';
      else
        return 10 + (c - 'A');
    };
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int cur = f(s[j]);
        for (int k = 3; k >= 0; k--) {
          g[i][j * 4 + 4 - k] = (cur & (1 << k)) != 0 ? 1 : 0;
        }
      }
    }
    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + g[i][j] - sum[i - 1][j - 1];
      }
    }
    auto getSub = [&sum](int l, int r, int x) {
      return sum[l + x - 1][r + x - 1] - sum[l - 1][r + x - 1] -
             sum[l + x - 1][r - 1] + sum[l - 1][r - 1];
    };
    for (int x = n; x > 0; x--) {
      if ((n % x) == 0) {
        bool ok = true;
        for (int i = 1; i <= n; i += x) {
          for (int j = 1; j <= n; j += x) {
            int cur = getSub(i, j, x);
            if (cur != x * x && cur != 0) {
              ok = false;
              break;
            }
          }
          if (!ok) break;
        }
        if (ok) {
          cout << x << endl;
          break;
        }
      }
    }
  }
};
class p917A {
 public:
  long long ans = 0;
  vector<int> dp;
  void solve() {
    ans = 0;
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
      bool ok = true;
      int cnt = 0;
      for (int j = i; j < n; j++) {
        if (s[j] == ')')
          cnt--;
        else
          cnt++;
        if (cnt < 0) ok = false;
        f[i][j] = ok;
      }
    }
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      bool ok = true;
      for (int j = i; j >= 0; j--) {
        if (s[j] == '(')
          cnt--;
        else
          cnt++;
        if (cnt < 0) ok = false;
        g[j][i] = ok;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j += 2) {
        if (f[i][j] && g[i][j]) ans++;
      }
    }
    cout << ans << endl;
  }
};
class p946D {
 public:
  void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0x3f3f3f3f));
    for (int i = 0; i <= k; i++) dp[0][i] = 0;
    vector<vector<int>> cnt(n + 1, vector<int>(k + 1, 0x3f3f3f3f));
    for (int i = 1; i <= n; i++) {
      unordered_map<int, int> last;
      int sum = 0, total = 0;
      for (int j = 1; j <= m; j++) total += (a[i][j - 1] == '1' ? 1 : 0);
      last[0] = 0;
      for (int j = 1; j <= m; j++) {
        if (a[i][j - 1] == '1') sum++;
        last[sum] = j;
        for (int l = 0; l <= min(total, k); l++) {
          if (last.count(sum - total + l)) {
            cnt[i][l] = min(cnt[i][l], j - last[sum - total + l]);
          }
        }
      }
      for (int l = 0; l <= k; l++) {
        for (int r = 0; r <= min(total, l); r++) {
          dp[i][l] = min(dp[i][l], dp[i - 1][l - r] + cnt[i][r]);
        }
      }
    }
    cout << dp[n][k] << endl;
  }
};
class p666A {
 public:
  void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    set<string> res;
    dp[n][0] = dp[n][1] = 1;
    dp[n - 2][0] = 1;
    if (n >= 7) res.insert(s.substr(n - 2, 2));
    dp[n - 3][1] = 1;
    if (n >= 8) res.insert(s.substr(n - 3, 3));
    for (int i = n - 4; i >= 5; i--) {
      if (dp[i + 2][1] == 1 ||
          (dp[i + 2][0] == 1 && (s[i] != s[i + 2] || s[i + 1] != s[i + 3]))) {
        dp[i][0] = 1;
        res.insert(s.substr(i, 2));
      }
      if (dp[i + 3][0] == 1 ||
          (dp[i + 3][1] == 1 && (s[i] != s[i + 3] || s[i + 1] != s[i + 4] ||
                                 s[i + 2] != s[i + 5]))) {
        dp[i][1] = 1;
        res.insert(s.substr(i, 3));
      }
    }
    cout << res.size() << endl;
    for (string s : res) cout << s << endl;
  }
};
class p1016C {
 public:
  void solve() {
    long long n;
    cin >> n;
    vector<vector<long long>> a(2, vector<long long>(n + 1, 0));
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    vector<vector<long long>> sum1(2, vector<long long>(n + 1, 0)),
        sum2(2, vector<long long>(n + 1, 0)),
        sum3(2, vector<long long>(n + 1, 0));
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) {
        sum3[i][j] += sum3[i][j - 1] + a[i][j];
        sum1[i][j] += sum1[i][j - 1] + (j - 1) * a[i][j];
        sum2[i][j] += sum2[i][j - 1] + (n - j) * a[i][j];
      }
    }
    long long res = 0;
    long long cur = 0;
    for (int c = 0; c < 2 * n; c++) {
      int j = c / 2 + 1;
      int i = ((j % 2) + (c % 2) + 1) % 2;
      cur += c * a[i][j];
      if ((j % 2) == i) continue;
      long long aa =
          (sum1[i][n] - sum1[i][j] + (c + 1 - j) * (sum3[i][n] - sum3[i][j]));
      long long bb = (sum2[1 ^ i][n] - sum2[1 ^ i][j - 1] +
                      (n + j - 1) * (sum3[1 ^ i][n] - sum3[1 ^ i][j - 1]));
      res = max(res, cur + aa + bb);
    }
    cout << res << endl;
  }
};
class p1133E {
 public:
  void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
    vector<long long> a(n, 0);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    long long res = 0;
    for (int j = 1; j <= k; j++) {
      for (int i = 1; i <= n; i++) {
        dp[i][j] = dp[i - 1][j];
        auto it = lower_bound(a.begin(), a.end(), a[i - 1] - 5);
        if (it == a.end()) {
          if (dp[0][j - 1] != -1) dp[i][j] = max(dp[i][j], dp[0][j - 1] + 1);
        } else {
          int pre = it - a.begin();
          if (dp[pre][j - 1] != -1) {
            dp[i][j] = max(dp[i][j], dp[pre][j - 1] + i - pre);
          }
        }
        res = max(res, dp[i][j]);
      }
    }
    cout << res << endl;
  }
};
class p2345H {
 public:
  void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<bool>> ok(n + 2, vector<bool>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      ok[i][i] = dp[i][i] = 1;
      ok[i + 1][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
      for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
        if (s[i - 1] == s[j - 1]) {
          ok[i][j] = ok[i + 1][j - 1];
          if (ok[i][j] != 0) dp[i][j] += 1;
        }
      }
    }
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      printf("%lld\n", dp[l][r]);
    }
  }
};
class p733C {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) cin >> b[i];
    vector<tuple<int, char>> res;
    int start = 0;
    bool flag = true;
    for (int i = 0; i < k && start < n; i++) {
      int sum = 0;
      int mx = start, end = start;
      while (sum < b[i] && end < n) {
        sum += a[end];
        if (a[end] > a[mx]) mx = end;
        end++;
      }
      if (sum != b[i]) {
        flag = false;
        break;
      }
      if (end - start == 1) {
        start++;
        continue;
      }
      int k = start;
      bool ok = false;
      for (; k < end; k++) {
        if (a[k] == a[mx]) {
          if (k > start && a[k - 1] < a[k]) ok = true;
          if (k + 1 < end && a[k + 1] < a[k]) ok = true;
        }
        if (ok) break;
      }
      if (!ok) {
        flag = false;
        break;
      }
      if (k > start && a[k - 1] < a[k]) {
        for (int l = k; l > start; l--)
          res.emplace_back(i + l - start + 1, 'L');
        for (int r = k; r < end - 1; r++) res.emplace_back(i + 1, 'R');
      } else {
        for (int r = k; r < end - 1; r++)
          res.emplace_back(i + k - start + 1, 'R');
        for (int l = k; l > start; l--)
          res.emplace_back(i + l - start + 1, 'L');
      }
      start = end;
    }
    if (!flag || res.size() != n - k)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (auto &[x, y] : res) {
        cout << x << " " << y << endl;
      }
    }
  }
};
class p914C {
 public:
  static const int maxn = 1005;
  long long f[maxn];
  long long c[maxn][maxn];
  void init() {
    const int maxn = 1001;
    f[1] = 0;
    for (int i = 2; i < maxn; i++) {
      int cnt = bitset<32>(i).count();
      f[i] = 1 + f[cnt];
    }
    memset(c, 0, sizeof(c));
    c[0][0] = 1;
    for (int i = 1; i < maxn; i++) {
      c[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 1000000007;
      }
    }
  }
  void solve() {
    int k;
    string s;
    cin >> s >> k;
    int n = s.size();
    if (k == 0) {
      if (s[0] >= 1)
        cout << 1 << endl;
      else
        cout << 0 << endl;
      return;
    }
    if (k == 1) {
      cout << n - 1 << endl;
      return;
    }
    init();
    long long res = 0;
    vector<long long> dp(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        for (int j = 0; j <= n - i - 1; j++) {
          if (f[cnt + j] == k - 1) {
            res = (res + c[n - i - 1][j]) % 1000000007;
          }
        }
        cnt++;
      }
    }
    if (f[cnt] == k - 1) res = (res + 1) % 1000000007;
    cout << res << endl;
  }
};
class p358D {
 public:
  static const int maxn = 3001;
  int n;
  int a[maxn], b[maxn], c[maxn];
  int dp[maxn][2][2];
  void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    memset(dp, -1, sizeof(dp));
    dp[0][0][1] = b[0];
    dp[0][0][0] = a[0];
    for (int i = 1; i < n; i++) {
      dp[i][0][0] = max(dp[i - 1][1][1] + a[i], dp[i - 1][0][1] + a[i]);
      dp[i][0][1] = max(dp[i - 1][1][1] + b[i], dp[i - 1][0][1] + b[i]);
      dp[i][1][0] = max(dp[i - 1][1][0] + b[i], dp[i - 1][0][0] + b[i]);
      dp[i][1][1] = max(dp[i - 1][1][0] + c[i], dp[i - 1][0][0] + c[i]);
    }
    cout << max(dp[n - 1][1][0], dp[n - 1][0][0]) << endl;
  }
};
class p700B {
 public:
  unordered_set<int> us;
  vector<vector<int>> edge;
  vector<int> seq;
  vector<int> dis;
  vector<int> lg;
  vector<vector<int>> dp;
  void dfs(int u, int fa, int depth) {
    dis[u] = depth;
    if (us.count(u)) seq.push_back(u);
    dp[u][0] = fa;
    for (int i = 1; (1 << i) <= depth; i++) {
      dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (auto c : edge[u]) {
      if (c == fa) continue;
      dfs(c, u, depth + 1);
    }
  }
  int lca(int x, int y) {
    if (dis[x] < dis[y]) swap(x, y);
    while (dis[x] > dis[y]) x = dp[x][lg[dis[x] - dis[y]] - 1];
    if (x == y) return x;
    for (int k = lg[dis[x]] - 1; k >= 0; k--) {
      if (dp[x][k] != dp[y][k]) {
        x = dp[x][k];
        y = dp[y][k];
      }
    }
    return dp[x][0];
  }
  void solve() {
    int n, k;
    cin >> n >> k;
    lg = vector<int>(n + 1, 0);
    dp = vector<vector<int>>(n + 1, vector<int>(21, 0));
    for (int i = 1; i <= n; i++) {
      lg[i] = lg[i - 1];
      if (i == (1 << lg[i - 1])) lg[i]++;
    }
    us.clear();
    seq.clear();
    for (int i = 0; i < 2 * k; i++) {
      int a;
      cin >> a;
      us.insert(a);
    }
    edge = vector<vector<int>>(n + 1);
    dis = vector<int>(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      edge[x].push_back(y);
      edge[y].push_back(x);
    }
    dfs(1, 0, 0);
    int res = 0;
    for (int i = 0; i < k; i++) {
      int u = lca(seq[i], seq[i + k]);
      res += dis[seq[i]] + dis[seq[i + k]] - 2 * dis[u];
    }
    cout << res << endl;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  p700B ans;
  ans.solve();
  return 0;
}
