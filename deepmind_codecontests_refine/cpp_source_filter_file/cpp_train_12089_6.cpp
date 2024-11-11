#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
const int LOG = 20;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long sq(long long x) { return (x * x) % MOD; }
long long modP(long long a, long long b) {
  return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);
}
int n, p[maxN], pw;
int R[maxN][LOG];
int a[maxN], l[maxN], r[maxN];
stack<int> st;
vector<int> vec[3];
bool cmp(int x, int y) {
  if (R[x][pw - 1] != R[y][pw - 1]) return (R[x][pw - 1] < R[y][pw - 1]);
  int tmp = (1 << (pw - 1));
  if (max(x, y) + tmp > n) return (x > y);
  return (R[x + tmp][pw - 1] < R[y + tmp][pw - 1]);
}
int LCP(int x, int y) {
  if (x == y) return n - x + 1;
  int ans1 = 0;
  for (int i = LOG - 1; i > -1 && x <= n && y <= n; i--) {
    if (R[x][i] == R[y][i]) {
      ans1 += (1 << i);
      x += (1 << i);
      y += (1 << i);
    }
  }
  return ans1;
}
long long solve(int b) {
  sort(vec[b].begin(), vec[b].end(), cmp);
  long long ans = 0;
  int sz = vec[b].size();
  for (int i = 1; i < sz; i++) a[i] = LCP(vec[b][i], vec[b][i - 1]);
  for (int i = 1; i < sz; i++) {
    while (!st.empty() && a[st.top()] > a[i]) st.pop();
    l[i] = (st.empty() ? 0 : st.top());
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = sz - 1; i > 0; i--) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    r[i] = (st.empty() ? sz : st.top());
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = 1; i < sz; i++) {
    ans += 1ll * a[i] * (i - l[i]) * (r[i] - i);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    R[i][0] = s[i - 1];
    p[i] = i;
  }
  for (pw = 1; pw < LOG; pw++) {
    sort(p + 1, p + n + 1, cmp);
    R[p[1]][pw] = 1;
    for (int i = 2; i <= n; i++)
      R[p[i]][pw] = R[p[i - 1]][pw] + cmp(p[i - 1], p[i]);
  }
  while (q--) {
    vec[0].clear();
    vec[1].clear();
    vec[2].clear();
    int s1, s2, inp;
    cin >> s1 >> s2;
    while (s1--) {
      cin >> inp;
      vec[0].push_back(inp);
      vec[2].push_back(inp);
    }
    while (s2--) {
      cin >> inp;
      vec[1].push_back(inp);
      vec[2].push_back(inp);
    }
    long long res = solve(0) + solve(1);
    res = solve(2) - res;
    cout << res << "\n";
  }
  return 0;
}
