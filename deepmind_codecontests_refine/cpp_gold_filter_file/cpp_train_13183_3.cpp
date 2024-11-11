#include <bits/stdc++.h>
using namespace std;
const long long inf = 9.2e18;
const int maxn = 2e5 + 70;
const int INF = 2.1e9;
const int maxm = 1e6 + 70;
const int MOD = 1e9 + 7;
const double eps = 1e-7;
const double PI = acos(-1.0);
long long n, m, k, x, y;
vector<int> a, b;
bool vis[30];
long long solve(int p) {
  long long m;
  for (int i = a.size() - 1; i >= 0; i--) {
    if (!vis[i]) {
      m = a[i];
      break;
    }
  }
  long long ans;
  if (m < b[p - 1]) {
    ans = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
      if (!vis[i]) {
        ans *= 10;
        ans += a[i];
      }
    }
    return ans;
  } else {
    long long t;
    for (int i = 0; i < a.size(); i++) {
      if (!vis[i]) {
        t = a[i];
        break;
      }
    }
    if (t > b[p - 1]) return -1;
    for (int i = a.size() - 1; i >= 0; i--) {
      if (!vis[i] && a[i] <= b[p - 1]) {
        t = i;
        m = a[i];
        break;
      }
    }
    if (m < b[p - 1]) {
      vis[t] = 1;
      ans = m;
      for (int i = a.size() - 1; i >= 0; i--) {
        if (!vis[i]) {
          ans *= 10;
          ans += a[i];
        }
      }
      return ans;
    } else {
      if (p == 1)
        return m;
      else {
        vis[t] = 1;
        long long d = solve(p - 1);
        vis[t] = 0;
        if (d != -1) {
          ans = m;
          for (int i = 1; i < p; i++) ans *= 10;
          ans += d;
          return ans;
        } else {
          m = -1;
          for (int i = a.size() - 1; i >= 0; i--) {
            if (!vis[i] && a[i] < b[p - 1]) {
              t = i;
              m = a[i];
              break;
            }
          }
          if (m != -1) {
            vis[t] = 1;
            ans = m;
            for (int i = a.size() - 1; i >= 0; i--) {
              if (!vis[i]) {
                ans *= 10;
                ans += a[i];
              }
            }
            return ans;
          } else
            return -1;
        }
      }
    }
  }
}
int main() {
  while (cin >> x >> y) {
    memset(vis, 0, sizeof(vis));
    a.clear();
    b.clear();
    long long t = x;
    while (t) {
      a.push_back(t % 10);
      t /= 10;
    }
    t = y;
    while (t) {
      b.push_back(t % 10);
      t /= 10;
    }
    long long ans;
    if (a.size() < b.size()) {
      sort(a.begin(), a.end());
      ans = 0;
      for (int i = a.size() - 1; i >= 0; i--) {
        ans *= 10;
        ans += a[i];
      }
    } else {
      sort(a.begin(), a.end());
      ans = solve(a.size());
    }
    cout << ans << endl;
  }
  return 0;
}
