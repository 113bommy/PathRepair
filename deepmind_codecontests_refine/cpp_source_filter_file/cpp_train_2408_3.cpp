#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N], p[N], Min[N], w[N];
struct E {
  long long a, b, w;
  bool operator<(const E& t) const { return w < t.w; }
} edgs[N * 2];
int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}
int main() {
  int n, m;
  cin >> n >> m;
  long long Min_ = 1e9, temp = -1;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    if (Min_ > w[i]) Min_ = w[i], temp = i;
  }
  for (int i = 1; i <= n; i++) p[i] = i;
  int idx = 1;
  for (int i = 1; i <= m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    edgs[idx++] = {a, b, c};
  }
  for (int i = 1; i <= n; i++) {
    if (temp == i) continue;
    edgs[idx++] = {temp, i, Min_ + w[i]};
  }
  sort(edgs + 1, edgs + idx);
  long long res = 0;
  for (int i = 1; i < idx; i++) {
    int a = find(edgs[i].a), b = find(edgs[i].b);
    if (a != b) {
      p[a] = b;
      res += edgs[i].w;
    }
  }
  cout << res << endl;
  return 0;
}
