#include <bits/stdc++.h>
using namespace std;
int p[105];
int a[105];
int mi[105], ma[105];
struct Item {
  int id;
  int a;
  bool operator<(const Item &rhs) const & { return rhs.a > a; }
} item[105];
int fi(int x, int m) {
  for (int i = 1; i <= m; i++)
    if (p[i] == x) return 1;
  return 0;
}
int check(int l, int r) {
  for (int i = l; i <= r; i++) {
    if (r < mi[i] || l > ma[i]) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      cin >> item[i].a, a[i] = item[i].a, item[i].id = i;
    for (int i = 1; i <= m; i++) cin >> p[i];
    sort(p + 1, p + m + 1);
    sort(item + 1, item + n + 1);
    queue<Item> q;
    q.push(item[1]);
    for (int i = 2; i <= n; i++) {
      if (item[i].a != q.back().a) {
        int maxv = i - 1;
        while (!q.empty()) {
          ma[q.front().id] = maxv;
          q.pop();
        }
      }
      q.push(item[i]);
      if (i == n) {
        while (!q.empty()) {
          ma[q.front().id] = n;
          q.pop();
        }
      }
    }
    q.push(item[n]);
    for (int i = n - 1; i >= 1; i--) {
      if (item[i].a != q.back().a) {
        int minv = i;
        while (!q.empty()) {
          mi[q.front().id] = minv;
          q.pop();
        }
      }
      q.push(item[i]);
      if (i == 1) {
        while (!q.empty()) {
          mi[q.front().id] = 1;
          q.pop();
        }
      }
    }
    if (!fi(1, m)) {
      if (mi[1] > 1) {
        cout << "NO" << endl;
        continue;
      }
    }
    int last = 1;
    int ok = 1;
    for (int i = 2; i <= n; i++) {
      if (fi(i, m)) continue;
      if (!check(last, i)) {
        ok = 0;
        break;
      }
      last = i + 1;
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
