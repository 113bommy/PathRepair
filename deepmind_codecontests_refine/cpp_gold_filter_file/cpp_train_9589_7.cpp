#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <class T>
ostream& prnt(ostream& out, T v) {
  out << v.size() << '\n';
  for (auto e : v) out << e << ' ';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<T> v) {
  return prnt(out, v);
}
template <class T>
ostream& operator<<(ostream& out, set<T> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ' ' << p.second << ')';
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const long long N = 100100;
long long n, lg, w[N], s, dp[N], a, ans;
vector<long long> v[N], first;
long long cb() {
  long long l = 0, r = min((long long)first.size() - 2, lg - 1);
  while (l != r) {
    long long mid = (l + r + 1) / 2;
    if (first.back() - first[first.size() - mid - 2] <= s)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}
void dfs(long long node, long long tot) {
  first.push_back(tot);
  long long up = -1;
  for (auto i : v[node]) {
    dfs(i, tot + w[i]);
    up = max(up, dp[i] - 1);
  }
  if (up == -1)
    dp[node] = cb(), ans++;
  else
    dp[node] = up;
  first.pop_back();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> lg >> s;
  for (long long i = 1; i <= n; i++) {
    cin >> w[i];
    if (w[i] > s) return cout << "-1\n", 0;
  }
  for (long long i = 2; i <= n; i++) {
    cin >> a;
    v[a].push_back(i);
  }
  first.push_back(0);
  dfs(1, w[1]);
  cout << ans << '\n';
}
