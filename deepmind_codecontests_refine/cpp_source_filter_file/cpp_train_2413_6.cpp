#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  long long idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ", ";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
const long long N = 200007;
vector<long long> cright(N + 1, -1), cleft(N + 1, -1);
void init() {}
long long travel(long long y1, long long y2) {
  long long mn = LLONG_MIN;
  long long cons = abs(y2 - y1);
  if (cright[y1] != -1) {
    if (cright[y1] <= y2) {
      mn = min(mn, cons);
    } else
      mn = min(mn, cons + 2 * abs(cright[y1] - max(y1, y2)));
  }
  if (cleft[y1] != -1) {
    if (cleft[y1] >= y2) {
      mn = min(mn, cons);
    } else
      mn = min(mn, cons + 2 * abs(cleft[y1] - min(y1, y2)));
  }
  return mn;
}
void solve() {
  long long i, j, k, n, m, q;
  long long x, y, l, r, p, val;
  cin >> n >> m >> k >> q;
  vector<long long> temp[n + 1];
  for (i = 0; i < k; i++) {
    cin >> x >> y;
    temp[x].push_back(y);
  }
  for (i = 1; i <= n; i++) {
    sort((temp[i]).begin(), (temp[i]).end());
  }
  vector<long long> safe(m + 1, false);
  for (i = 0; i < q; i++) {
    cin >> x;
    safe[x] = true;
  }
  for (i = 1; i <= m; i++) {
    if (safe[i] == true)
      cleft[i] = i;
    else if (cleft[i - 1] != -1)
      cleft[i] = cleft[i - 1];
  }
  for (i = m; i >= 1; i--) {
    if (safe[i] == true)
      cright[i] = i;
    else if (cright[i + 1] != -1)
      cright[i] = cright[i + 1];
  }
  if (k == 0) {
    cout << 0 << endl;
    return;
  }
  long long dp[n + 1][2], last = -1;
  long long lastmn, lastmx, mx, mn;
  for (i = n; i >= 1; i--) {
    if (temp[i].size() == 0) continue;
    mn = temp[i][0], mx = temp[i][temp[i].size() - 1];
    if (last == -1) {
      dp[i][0] = mx - mn, dp[i][1] = abs(mx - mn);
    } else {
      dp[i][0] = abs(mx - mn) +
                 min((travel(mx, lastmx) + dp[last][1]),
                     (travel(mx, lastmn) + dp[last][0])) +
                 last - i;
      dp[i][1] = abs(mx - mn) +
                 min((travel(mn, lastmx) + dp[last][1]),
                     (travel(mn, lastmn) + dp[last][0])) +
                 last - i;
    }
    lastmn = mn, lastmx = mx;
    last = i;
  }
  if (last == 1) {
    cout << min(abs(lastmx - 1) + dp[last][1], abs(lastmn - 1) + dp[last][0]) +
                (last - 1)
         << endl;
  } else
    cout << min(travel(1, lastmx) + dp[last][1],
                travel(1, lastmn) + dp[last][0]) +
                (last - 1)
         << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  for (long long pp = 1; pp <= t; pp++) {
    solve();
  }
  return 0;
}
