#include <bits/stdc++.h>
using namespace std;
const int MAX = 210000;
const long long base = 1e9 + 7;
struct Node {
  int l, r;
};
void solve() {
  long long result = 0;
  int n, s, m, k;
  cin >> n >> s >> m >> k;
  vector<int> za(n);
  int maxa = -1;
  for (int i = 0; i < n; ++i) {
    cin >> za[i];
    maxa = max(za[i], maxa);
  }
  vector<vector<Node> > pool(n);
  for (int i = 0; i < s; ++i) {
    Node z;
    cin >> z.l >> z.r;
    z.l--;
    z.r--;
    if (pool[z.l].size() > 0) {
      if (pool[z.l].front().r < z.r) {
        pool[z.l][0] = z;
      }
    } else {
      pool[z.l].push_back(z);
    }
  }
  auto Work = [&](int r) {
    vector<int> acc(n + 1);
    acc[0] = 0;
    for (int i = 0; i < n; ++i) {
      acc[i + 1] = acc[i];
      if (za[i] <= r) {
        acc[i + 1]++;
      }
    }
    vector<vector<int> > dp(n + 2);
    for (int i = 0; i <= n; ++i) {
      dp[i] = vector<int>(m + 1, 0);
    }
    int cr = -1;
    for (int i = 0; i < n; ++i) {
      if (pool[i].size() > 0) {
        Node z = pool[i][0];
        cr = max(cr, z.r);
      }
      int add = acc[cr + 1] - acc[i];
      if (add > 0) {
        for (int j = 0; j < m; j++) {
          dp[cr + 1][j + 1] = max(dp[cr + 1][j + 1], dp[i][j] + add);
        }
      }
      for (int j = 0; j < m + 1; j++) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      }
    }
    for (int j = 0; j < m + 1; ++j) {
      if (dp[n][j] >= k) return true;
    }
    return false;
  };
  bool f = Work(maxa);
  if (!f) {
    cout << -1;
    return;
  }
  int mina = 0;
  while (mina + 1 < maxa) {
    int mid = (mina + maxa + 1) / 2;
    bool f = Work(mid);
    if (f) {
      maxa = mid;
    } else {
      mina = mid;
    }
  }
  cout << maxa << endl;
}
int main() {
  const int inId = 0;
  const int outId = 0;
  if (inId > 0) {
    cerr << "redirect stdin to input " << inId << endl;
    string s = "input";
    s += to_string(inId);
    s += ".txt";
    auto r = freopen(s.c_str(), "r", stdin);
    if (r == nullptr) {
      cerr << "invalid input file " << s;
    }
  }
  if (outId > 0) {
    cerr << "redirect stdout to stdout " << outId << endl;
    string s = "stdout";
    s += to_string(outId);
    s += ".txt";
    auto r = freopen(s.c_str(), "w", stdout);
    if (r == nullptr) {
      cerr << "invalid output file " << s;
    }
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  solve();
}
