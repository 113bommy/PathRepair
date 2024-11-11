#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  return x * f;
}
inline void out(int x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 + 48);
}
inline void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  out(x), puts("");
}
const int N = 2e5 + 10;
int a[N], cnt, num[N * 20], ans, posx, posy, vis[N * 20];
vector<int> v[N * 20];
unordered_map<int, int> mp;
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1, x = a[i]; i <= n; i++, x = a[i]) {
    if (mp.find(x) == mp.end()) mp[x] = ++cnt;
    num[mp[x]] = i;
    while (x) {
      int k = log2(x) + 1, y = (1 << k) - x;
      if (mp.find(x) == mp.end()) mp[x] = ++cnt;
      if (mp.find(y) == mp.end()) mp[y] = ++cnt;
      if (x == y) {
        v[0].push_back(mp[x]), v[mp[x]].push_back(0);
        break;
      }
      v[mp[x]].push_back(mp[y]), v[mp[y]].push_back(mp[x]), x = y;
    }
  }
  queue<int> q;
  num[0] = num[mp[0]], mp[0] = vis[0] = 0, q.push(0);
  int posx, posy;
  while (q.size()) {
    int x = q.front();
    q.pop();
    if (num[x]) posx = x;
    for (int y : v[x]) {
      if (vis[y]) continue;
      vis[y] = 1, q.push(y);
    }
  }
  q.push(posx), memset(vis, 0, sizeof vis), vis[posx] = 1;
  while (q.size()) {
    int x = q.front();
    q.pop();
    if (num[x]) posy = x, ans = vis[x] - 1;
    for (int y : v[x]) {
      if (vis[y]) continue;
      vis[y] = vis[x] + 1, q.push(y);
    }
  }
  cout << num[posx] << " " << num[posy] << " " << ans;
}
