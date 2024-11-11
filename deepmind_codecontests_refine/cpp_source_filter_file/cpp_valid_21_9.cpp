#include <bits/stdc++.h>
using namespace std;
string to_string(const string& str) { return str; }
template <typename T>
string to_string(const set<T>& mys) {
  if (mys.empty()) return "{}";
  string ret = "{";
  for (auto el : mys) ret += to_string(el) + ", ";
  ret.pop_back(), ret.pop_back();
  ret += "}";
  return ret;
}
template <typename T>
string to_string(const pair<T, T>& pr) {
  return "(" + to_string(pr.first) + "," + to_string(pr.second) + ")";
}
template <typename T>
string to_string(const vector<T>& vc, int w) {
  if (vc.empty()) return "";
  if (w + 1 == vc.size()) return to_string(vc[w]);
  return to_string(vc[w]) + "," + to_string(vc, w + 1);
}
template <typename T>
string to_string(const vector<T>& vc) {
  return "{" + to_string(vc, 0) + "}";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
class DebugStream {
} LOG;
template <typename T>
DebugStream& operator<<(DebugStream& s, const T&) {
  return s;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int maxN = 2e5 + 9, maxV = 1e6 + 9, MOD = 998244353, SQ = 335, lg = 20,
          bs = 29;
long long n, x[maxN], y[maxN], pref[maxN], vlu[maxN];
int state[maxN], nxt[maxN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> state[i];
  for (int i = 1; i <= n; i++)
    nxt[i] = int(upper_bound(x, x + n + 1, y[i]) - x);
  long long sumat = 0;
  for (int i = 1; i <= n; i++) {
    long long cnd = (MOD + sumat - pref[nxt[i] - 1]) % MOD;
    vlu[i] = (cnd + x[i] - y[i]) % MOD;
    sumat = (sumat + vlu[i]) % MOD;
    pref[i] = (vlu[i] + pref[i - 1]) % MOD;
  }
  long long ans = x[n] + 1;
  for (int i = 1; i <= n; i++)
    if (state[i]) ans = (ans + vlu[i]) % MOD;
  cout << ans << '\n';
}
