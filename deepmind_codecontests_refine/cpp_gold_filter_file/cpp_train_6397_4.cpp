#include <bits/stdc++.h>
#pragma GCC optimise("ofast")
#pragma GCC optimise("unroll-loops")
using namespace std;
const int N = 300000 + 10;
const long long MOD = 1000000000 + 7;
const long long INF = 1000000000000000000;
const long long LOG = 20;
string second, s, s1, s2;
long long R[N][LOG], p[N], pw, lcp[N], n, l[N], r[N], par[N][3], ans[N];
bool cmp(int x, int y) {
  if (R[x][pw] != R[y][pw]) return R[x][pw] < R[y][pw];
  if (max(x, y) + (1 << pw) > n) return x > y;
  return R[x + (1 << pw)][pw] < R[y + (1 << pw)][pw];
}
int GetLcp(int x, int y) {
  int res = 0;
  for (int i = LOG - 1; i >= 0 && x <= n && y <= n; i--) {
    if (R[x][i] == R[y][i]) {
      res ^= (1 << i), x += (1 << i), y += (1 << i);
    }
  }
  return res;
}
void BuildSuffixArray() {
  n = s.size();
  for (int i = 1; i <= n; i++) {
    p[i] = i, R[i][0] = s[i - 1];
  }
  for (pw = 0; pw < LOG - 1; pw++) {
    sort(p + 1, p + n + 1, cmp);
    R[p[1]][pw + 1] = 1;
    for (int i = 2; i <= n; i++) {
      R[p[i]][pw + 1] = R[p[i - 1]][pw + 1] + cmp(p[i - 1], p[i]);
    }
  }
  for (int i = 1; i < s.size(); i++) {
    lcp[i] = GetLcp(p[i], p[i + 1]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> second >> s1 >> s2;
  s = second + "#" + s1 + "$" + s2;
  BuildSuffixArray();
  lcp[0] = -1, lcp[n] = -1;
  stack<int> st;
  st.push(0);
  for (int i = 1; i < n; i++) {
    while (lcp[st.top()] >= lcp[i]) st.pop();
    l[i] = st.top();
    st.push(i);
  }
  while (st.size()) st.pop();
  st.push(n);
  for (int i = n - 1; i > 0; i--) {
    while (lcp[st.top()] > lcp[i]) st.pop();
    r[i] = st.top();
    st.push(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) par[i][j] = par[i - 1][j];
    if (s[p[i] - 1] == '#' || s[p[i] - 1] == '$') continue;
    if (p[i] <= second.size())
      par[i][0]++;
    else if (p[i] <= second.size() + s1.size() + 1)
      par[i][1]++;
    else
      par[i][2]++;
  }
  for (int i = 1; i < n; i++) {
    long long a[3];
    for (int k = 0; k < 3; k++) {
      a[k] = par[r[i]][k] - par[l[i]][k];
    }
    ans[lcp[i]] += a[0] * a[1] * a[2] % MOD;
    for (int k = 0; k < 3; k++) {
      a[k] = par[i][k] - par[l[i]][k];
    }
    ans[lcp[i]] -= a[0] * a[1] * a[2] % MOD;
    ans[lcp[i]] %= MOD;
    ans[lcp[i]] += MOD;
    ans[lcp[i]] %= MOD;
    for (int k = 0; k < 3; k++) {
      a[k] = par[r[i]][k] - par[i][k];
    }
    ans[lcp[i]] -= a[0] * a[1] * a[2] % MOD;
    ans[lcp[i]] %= MOD;
    ans[lcp[i]] += MOD;
    ans[lcp[i]] %= MOD;
  }
  for (int i = N - 1; i >= 0; i--) {
    ans[i] += ans[i + 1];
    ans[i] %= MOD;
  }
  for (int i = 1; i <= min(second.size(), min(s1.size(), s2.size())); i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
