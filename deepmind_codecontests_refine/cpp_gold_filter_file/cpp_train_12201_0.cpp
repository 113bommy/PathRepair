#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return w == 1 ? x : -x;
}
struct node {
  long long x, y, w, k;
} p[200005];
long long w[200005], tmp, pre[200005], cnt2;
bool vis[200005], vis2[200005];
vector<int> ans1;
inline long long dis(node a, node b) { return abs(a.x - b.x) + abs(a.y - b.y); }
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) p[i].x = read(), p[i].y = read();
  for (int i = 1; i <= n; i++) p[i].w = read();
  for (int i = 1; i <= n; i++) p[i].k = read();
  for (int i = 1; i <= n; i++) w[i] = p[i].w;
  for (int i = 1; i <= n; i++) {
    long long ans = 1e18, fl = 1;
    for (int j = 1; j <= n; j++) {
      if (vis[j])
        continue;
      else if (w[j] < ans)
        ans = w[j], fl = j;
    }
    vis[fl] = 1;
    tmp += w[fl];
    if (vis2[fl] == 0) ans1.push_back(fl);
    for (int j = 1; j <= n; j++) {
      if (vis[j]) continue;
      if (w[j] > (p[fl].k + p[j].k) * dis(p[fl], p[j])) {
        w[j] = (p[fl].k + p[j].k) * dis(p[fl], p[j]);
        vis2[j] = 1;
        pre[j] = fl;
      }
    }
  }
  cout << tmp << endl;
  cout << ans1.size() << endl;
  for (int i = 0; i < ans1.size(); i++) printf("%d ", ans1[i]);
  cout << endl;
  for (int i = 1; i <= n; i++)
    if (vis2[i] == 1) cnt2++;
  cout << cnt2 << endl;
  for (int i = 1; i <= n; i++)
    if (vis2[i] == 1) printf("%d %d\n", i, pre[i]);
  return 0;
}
