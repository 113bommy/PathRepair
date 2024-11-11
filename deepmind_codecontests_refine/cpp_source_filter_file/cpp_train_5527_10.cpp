#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
};
long long dp[10005][2][2];
long long n, m;
vector<long long> items;
long long recur(int pos, bool taken, bool status) {
  if (pos == items.size()) {
    return 0;
  }
  if (dp[pos][taken][status] != -1) {
    return dp[pos][taken][status];
  }
  long long mx = 0;
  if (status) {
    mx = max(mx, items[pos] - items[pos - 1] + recur(pos + 1, taken, false));
    if (!taken) {
      mx =
          max(mx, items[pos] - items[pos - 1] - 1 + recur(pos + 1, true, true));
    }
  } else {
    mx = max(mx, recur(pos + 1, taken, true));
    if (!taken) {
      mx = max(mx,
               items[pos] - items[pos - 1] - 1 + recur(pos + 1, true, false));
    }
  }
  return dp[pos][taken][status] = mx;
}
void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  items.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> items[i];
  }
  items.push_back(m);
  items.insert(items.begin(), 0);
  long long ans = recur(1, false, true);
  cout << ans << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
