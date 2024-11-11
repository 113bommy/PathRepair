#include <bits/stdc++.h>
using namespace std;
long long read(long long x = 0, long long fr = 1, char c = getchar()) {
  while (c < '0' || c > '9') fr *= (c == '-') ? -1 : 1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * fr;
}
struct Portal {
  int x, y, p, q;
  Portal(int _x, int _y, int _p, int _q) : x(_x), y(_y), p(_p), q(_q) {}
};
vector<Portal> ans;
int n, a[1010], b[1010], c[1010], d[1010];
int ra[1010], rb[1010], rc[1010], rd[1010];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), ra[a[i]] = i;
  for (int i = 1; i <= n; ++i) b[i] = read(), rb[b[i]] = i;
  for (int i = 1; i <= n; ++i) c[i] = d[i] = rc[i] = rd[i] = i;
  for (int i = 1; i < n; ++i) {
    if (c[i] == ra[i] && d[i] == rb[i]) continue;
    ans.push_back(Portal(i, rc[ra[i]], rd[rb[i]], i));
    int t1 = c[i], t2 = d[i];
    swap(c[i], c[rc[ra[i]]]), swap(d[i], d[rd[rb[i]]]);
    swap(rc[ra[i]], rc[t1]), swap(rd[rb[i]], rd[t2]);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d %d %d\n", ans[i].y, ans[i].x, ans[i].q, ans[i].p);
  return 0;
}
