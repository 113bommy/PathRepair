#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10, MAXM = 4e6 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int MOD = 1e9 + 7, mod = 998244353;
const int inv2 = 5e8 + 4;
const double Pi = acos(-1);
int n;
int getid(int x, int y) { return x * n + y; }
bool check(int x, int y) { return x > -1 && y > -1 && x < n && y < n; }
int ans1, ans2;
bool vis[MAXN];
int a[MAXN];
void dfs1(int x, int y) {
  vis[getid(x, y)] = 1;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++)
    if (!vis[getid(x, i)]) v.push_back({a[getid(x, i)], getid(x, i)});
  for (int i = 0; i < n; i++)
    if (!vis[getid(i, y)]) v.push_back({a[getid(i, y)], getid(i, y)});
  for (int i = 1; i < n; i++) {
    if (check(x + i, y + i))
      if (!vis[getid(x + i, y + i)])
        v.push_back({a[getid(x + i, y + i)], getid(x + i, y + i)});
    if (check(x - i, y + i))
      if (!vis[getid(x - i, y + i)])
        v.push_back({a[getid(x - i, y + i)], getid(x - i, y + i)});
    if (check(x + i, y - i))
      if (!vis[getid(x + i, y - i)])
        v.push_back({a[getid(x + i, y - i)], getid(x + i, y - i)});
    if (check(x - i, y - i))
      if (!vis[getid(x - i, y - i)])
        v.push_back({a[getid(x - i, y - i)], getid(x - i, y - i)});
  }
  if (!((int)v.size())) {
    ans1++;
    for (int i = 0; i < n * n; i++)
      if (!vis[i]) {
        vis[i] = 1;
        dfs1(i / n, i % n);
        break;
      }
  } else {
    pair<int, int> q = *min_element((v).begin(), (v).end());
    int p = q.second;
    dfs1(p / n, p % n);
  }
}
void dfs2(int x, int y) {
  vis[getid(x, y)] = 1;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++)
    if (!vis[getid(x, i)]) v.push_back({a[getid(x, i)], getid(x, i)});
  for (int i = 0; i < n; i++)
    if (!vis[getid(i, y)]) v.push_back({a[getid(i, y)], getid(i, y)});
  if (!((int)v.size())) {
    ans2++;
    for (int i = 0; i < n * n; i++)
      if (!vis[i]) {
        vis[i] = 1;
        dfs2(i / n, i % n);
        break;
      }
  } else {
    pair<int, int> q = *min_element((v).begin(), (v).end());
    int p = q.second;
    dfs2(p / n, p % n);
  }
}
int b[] = {1, 2, 5, 7, 3, 8, 4, 6, 9};
int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14, 13, 16, 12, 15};
int main() {
  scanf("%d", &n);
  if (n == 1 || n == 2)
    return puts("-1"), 0;
  else if (n == 3) {
    for (int i = 0; i < n * n; i++) a[i] = b[i];
  } else if (n == 4) {
    for (int i = 0; i < n * n; i++) a[i] = c[i];
  } else if (n >= 5) {
    for (int i = 0; i < n * n; i++) a[i] = i + 1;
    int cnt = n * n;
    a[getid(n - 1, n - 3)] = cnt--;
    a[getid(n - 1, n - 1)] = cnt--;
    for (int i = n - 4; i > 0; i--) a[getid(n - 1, i)] = cnt--;
    a[getid(n - 2, n - 1)] = cnt--;
    a[getid(n - 1, n - 2)] = cnt--;
    a[getid(n - 1, 0)] = cnt--;
  }
  for (int i = 0; i < n; i++, puts(""))
    for (int j = 0; j < n; j++) printf("%d ", a[getid(i, j)]);
  return 0;
}
