#include <bits/stdc++.h>
using namespace std;
bool desc_sort(const int& lhs, const int& rhs) { return lhs > rhs; }
bool desc_pii_sort(const pair<int, int>& lhs, const pair<int, int>& rhs) {
  return lhs > rhs;
}
bool second_sort(const pair<int, int>& lhs, const pair<int, int>& rhs) {
  pair<int, int> a, b;
  a.first = lhs.second;
  a.second = lhs.first;
  b.first = rhs.second;
  b.second = rhs.first;
  return a < b;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> second) {
  os << "{ ";
  for (auto s : second) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
inline long long fast_expo(long long base, long long power,
                           long long modulo = 1e0) {
  base %= modulo;
  if (base < 0LL) base += modulo;
  long long x = base, cnt = power, ans = 1LL;
  while (cnt) {
    if (cnt & 1LL) ans = (ans * x) % modulo;
    x = (x * x) % modulo;
    cnt >>= 1LL;
  }
  return ans;
}
inline long long inv(long long base, long long modulo = 1e0) {
  return fast_expo(base, modulo - 2LL, modulo);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int bin[n + 1][24], dist[n + 1], endp[n + 1];
  bool vis[n + 1];
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) cin >> bin[i][0];
  for (int j = 1; j < 24; j++)
    for (int i = 1; i <= n; i++) {
      bin[i][j] = bin[bin[i][j - 1]][j - 1];
    }
  int v[m + 1];
  int b[m + 1];
  for (int i = 1; i <= m; i++) cin >> v[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  int res = 0;
  for (int i = 1; i <= m; i++) {
    int r = (v[i] + res - 1) % n + 1;
    res = 0;
    b[i]--;
    int end = r;
    for (int j = 0; j < 24; j++)
      if (b[i] & (1 << j)) end = bin[end][j];
    while (b[i] >= 0) {
      int t1, t2;
      if (vis[r]) {
        t1 = dist[r];
        t2 = endp[r];
        if (t1 < b[i]) {
          dist[r] = b[i];
          endp[r] = end;
        }
        if (t1 == 0) {
          t1 = 1;
          t2 = bin[r][0];
        }
      } else {
        vis[r] = 1;
        res++;
        t1 = 1;
        t2 = bin[r][0];
        dist[r] = b[i];
        endp[r] = end;
      }
      b[i] -= t1;
      r = t2;
    }
    cout << (res) << "\n";
  }
  return 0;
}
