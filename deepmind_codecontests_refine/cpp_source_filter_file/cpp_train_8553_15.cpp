#include <bits/stdc++.h>
using namespace std;
struct st {
  int x, y;
} a[200005];
int b[200005];
int c[200005];
int d[200005];
int n, cnt;
bool cmp(st a, st b) { return a.y < b.y; }
int update(int pos, int v) {
  for (int i = pos; i <= cnt; i += i & (-i)) {
    b[i] += v;
  }
  return 0;
}
int query(int x) {
  if (x == 0) return 0;
  int ans = 0;
  for (int i = cnt; i > 0; i -= i & (-i)) {
    ans += b[i];
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  set<int> s;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    s.insert(a[i].x);
  }
  map<int, int> mp;
  for (auto x : s) {
    c[++cnt] = x;
    mp[x] = cnt;
  }
  for (int i = 1; i <= n; i++) {
    d[mp[a[i].x]]++;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= cnt; i++) {
    update(i, 1);
  }
  long long ans = 0;
  int now = 1;
  while (now <= n) {
    int k = a[now].y;
    vector<int> v;
    v.push_back(0);
    v.push_back(cnt + 1);
    while (now <= n && a[now].y == k) {
      v.push_back(mp[a[now].x]);
      now++;
    }
    sort(v.begin(), v.end());
    long long x = query(cnt);
    ans += x * (x + 1) / 2;
    for (int i = 1; i < v.size(); i++) {
      if (v[i] == v[i - 1]) continue;
      long long x = query(v[i] - 1) - query(v[i - 1]);
      assert(x >= 0);
      ans -= x * (x + 1) / 2;
    }
    for (int i = 0; i < v.size(); i++) {
      d[v[i]]--;
      if (d[v[i]] == 0) update(v[i], -1);
    }
  }
  cout << ans << endl;
  return 0;
}
