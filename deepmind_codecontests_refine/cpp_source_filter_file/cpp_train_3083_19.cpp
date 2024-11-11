#include <bits/stdc++.h>
using namespace std;
const string alf = "abcdefghijklmnopqrstuvwxyz";
const int hashP = 239017;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 1e9;
const long long INF2 = 1e18;
template <typename T>
bool umn(T &a, T b) {
  return (a > b ? (a = b, 1) : 0);
}
template <typename T>
bool umx(T &a, T b) {
  return (a < b ? (a = b, 1) : 0);
}
long long cnt[511][511];
struct node {
  int x, y, t;
};
int main() {
  int n, m, k, q2;
  cin >> n >> m >> k >> q2;
  vector<node> a;
  for (int i = 0; i < q2; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    a.push_back({x, y, t});
  }
  sort(a.begin(), a.end(), [&](node l, node r) { return l.t < r.t; });
  int anss = 1e9 + 10, l = 0, r = 1e9 + 10;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cnt[i][j] = 0;
      }
    }
    for (int i = 0; i < q2; i++) {
      if (a[i].t <= mid) {
        cnt[a[i].x][a[i].y] = 1;
      } else
        break;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
      }
    }
    bool ans = 0;
    for (int i = k; i <= n; i++) {
      for (int j = k; j <= m; j++) {
        int ch = cnt[i][j] - cnt[i - k][j] - cnt[i][j - k] + cnt[i - k][j - k];
        if (ch == k * k) {
          ans = 1;
          r = mid;
          anss = min(anss, mid);
          break;
        }
      }
      if (ans) break;
    }
    if (!ans) l = mid;
  }
  int mid = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt[i][j] = 0;
    }
  }
  for (int i = 0; i < q2; i++) {
    if (a[i].t <= mid) {
      cnt[a[i].x][a[i].y] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
    }
  }
  bool ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int ch = cnt[i][j] - cnt[i - k][j] - cnt[i][j - k] + cnt[i - k][j - k];
      if (ch == k * k) {
        ans = 1;
        r = mid;
        anss = min(anss, mid);
        break;
      }
    }
    if (ans) break;
  }
  mid = 1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt[i][j] = 0;
    }
  }
  for (int i = 0; i < q2; i++) {
    if (a[i].t <= mid) {
      cnt[a[i].x][a[i].y] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
    }
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int ch = cnt[i][j] - cnt[i - k][j] - cnt[i][j - k] + cnt[i - k][j - k];
      if (ch == k * k) {
        ans = 1;
        r = mid;
        anss = min(anss, mid);
        break;
      }
    }
    if (ans) break;
  }
  if (anss != 1e9 + 10)
    cout << anss;
  else
    cout << "-1";
  return 0;
}
