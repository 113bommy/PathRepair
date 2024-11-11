#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxn = 1e5 + 5;
int a[maxn];
int res[maxn][3], c = 0;
inline void f(int i, int j, int k) {
  a[i] = !a[i];
  a[j] = !a[j];
  a[k] = !a[k];
  res[c][0] = i, res[c][1] = j, res[c][2] = k;
  ++c;
}
int vis[maxn], p[maxn], vv[maxn];
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  while (n > 15) {
    if (a[n] == 0) {
      --n;
      continue;
    }
    if (a[n] == 1 && a[n - 1] == 0 && a[n - 2] == 0) {
      f(n, n - 3, n - 6);
    }
    if (a[n] == 1 && a[n - 1] == 0 && a[n - 2] == 1) {
      f(n, n - 2, n - 4);
    }
    if (a[n] == 1 && a[n - 1] == 1 && a[n - 2] == 1) {
      f(n, n - 1, n - 2);
    }
    if (a[n] == 1 && a[n - 1] == 1 && a[n - 2] == 0) {
      if (a[n - 3] == 0 && a[n - 4] == 0 && a[n - 5] == 0) {
        f(n, n - 4, n - 8);
        f(n - 1, n - 4, n - 7);
      }
      if (a[n - 3] == 1 && a[n - 4] == 0 && a[n - 5] == 0) {
        f(n, n - 3, n - 6);
        f(n - 1, n - 6, n - 11);
      }
      if (a[n - 3] == 0 && a[n - 4] == 1 && a[n - 5] == 0) {
        f(n, n - 4, n - 8);
        f(n - 1, n - 6, n - 11);
      }
      if (a[n - 3] == 1 && a[n - 4] == 1 && a[n - 5] == 0) {
        f(n, n - 3, n - 6);
        f(n - 1, n - 4, n - 7);
      }
      if (a[n - 3] == 0 && a[n - 4] == 0 && a[n - 5] == 1) {
        f(n, n - 5, n - 10);
        f(n - 1, n - 6, n - 11);
      }
      if (a[n - 3] == 1 && a[n - 4] == 0 && a[n - 5] == 1) {
        f(n, n - 3, n - 6);
        f(n - 1, n - 5, n - 9);
      }
      if (a[n - 3] == 0 && a[n - 4] == 1 && a[n - 5] == 1) {
        f(n, n - 4, n - 8);
        f(n - 1, n - 5, n - 9);
      }
      if (a[n - 3] == 1 && a[n - 4] == 1 && a[n - 5] == 1) {
        f(n, n - 4, n - 8);
        f(n - 1, n - 3, n - 5);
      }
      n -= 6;
      continue;
    }
  }
  int ok = 0;
  int x = 0;
  for (int i = 1; i <= n; ++i) {
    x = x * 2 + a[i];
  }
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == 0) {
      ok = 1;
      break;
    }
    for (int d = 1; 2 * d < n; ++d) {
      for (int i = 0; i + 2 * d < n; ++i) {
        int t = u;
        if (t & (1 << i)) {
          t -= 1 << i;
        } else {
          t += 1 << i;
        }
        if (t & (1 << (i + d))) {
          t -= 1 << (i + d);
        } else {
          t += 1 << (i + d);
        }
        if (t & (1 << (i + d + d))) {
          t -= 1 << (i + d + d);
        } else {
          t += 1 << (i + d + d);
        }
        if (!vis[t]) {
          vis[t] = d;
          vv[t] = n - 2 * d - i;
          q.push(t);
          p[t] = u;
        }
      }
    }
  }
  if (!ok) {
    cout << "NO" << endl;
    return 0;
  }
  int u = 0;
  while (x != u) {
    int d = vis[u];
    f(vv[u], vv[u] + d, vv[u] + d + d);
    u = p[u];
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != 0) {
      cout << i << endl;
    }
  }
  cout << "YES" << endl;
  cout << c << endl;
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << res[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
