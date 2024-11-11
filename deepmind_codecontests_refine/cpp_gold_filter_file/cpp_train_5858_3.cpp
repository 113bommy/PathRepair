#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const long long M = 1e9 + 7;
const long long p = 31;
int dp[2][N + 1];
inline void mod(int& x) {
  if (x >= M) x -= M;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<string> ar(n);
  vector<vector<int>> ord;
  vector<vector<long long>> h;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ar[i] = s;
    int m = s.size();
    vector<long long> hsh(m);
    for (int i = 0; i < m; i++)
      hsh[i] = ((i > 0 ? hsh[i - 1] : 0) * p + (s[i] - 'a' + 1)) % M;
    h.push_back(hsh);
    vector<int> nxt(m, m - 1);
    for (int i = m - 2; i >= 0; i--) {
      if (s[i] == s[i + 1])
        nxt[i] = nxt[i + 1];
      else
        nxt[i] = i + 1;
    }
    vector<int> t(m + 1);
    int l = 0, r = m;
    for (int i = 0; i < m; i++) {
      if (i == m - 1)
        t[l] = m - 1, t[r] = m;
      else if (s[nxt[i]] > s[i])
        t[r] = i, r--;
      else
        t[l] = i, l++;
    }
    ord.push_back(t);
  }
  for (int i = 0; i <= ar[0].size(); i++) dp[0][i] = 1;
  vector<long long> _pow(N + 1);
  _pow[0] = 1;
  for (int i = 1; i <= N; i++) _pow[i] = (_pow[i - 1] * p) % M;
  auto _hash = [&](int i, int k, int j) {
    if (k >= j)
      return h[i][j - 1];
    else
      j++;
    return ((h[i][j - 1] - (h[i][k] * _pow[(j - 1) - k]) % M + M) % M +
            (k - 1 >= 0 ? (h[i][k - 1] * _pow[j - k - 1]) % M : 0)) %
           M;
  };
  auto _lcp = [&](int i, int k1, int j, int k2) {
    int lng1 = ar[i].size();
    lng1 -= (k1 < ar[i].size());
    int lng2 = ar[j].size();
    lng2 -= (k2 < ar[j].size());
    int l = 0, r = min(lng1, lng2);
    while (l < r) {
      int mid = (l + r) / 2;
      if (r - l == 1) mid = r;
      long long h1 = _hash(i, k1, mid);
      long long h2 = _hash(j, k2, mid);
      if (h1 == h2)
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  };
  auto _less = [&](int i, int k1, int j, int k2) {
    int lcp = _lcp(i, k1, j, k2);
    int lng1 = ar[i].size();
    lng1 -= (k1 < ar[i].size());
    int lng2 = ar[j].size();
    lng2 -= (k2 < ar[j].size());
    return ((lcp == lng1 && lng1 <= lng2) ||
            (ar[i][lcp + (k1 <= lcp)] <= ar[j][lcp + (k2 <= lcp)]));
  };
  for (int i = 1; i < n; i++) {
    int sum = 0, p = 0, w = i % 2;
    for (int j : ord[i]) {
      while (p < ord[i - 1].size() && _less(i - 1, ord[i - 1][p], i, j)) {
        sum += dp[w ^ 1][ord[i - 1][p]];
        mod(sum);
        p++;
      }
      dp[w][j] = sum;
    }
  }
  int ans = 0;
  for (int i = 0; i <= ar[n - 1].size(); i++)
    ans += dp[(n - 1) % 2][i], mod(ans);
  cout << ans;
}
