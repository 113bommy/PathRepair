#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6;
long long d0[N], d1[N];
int ask[N];
int n, m;
pair<int, pair<int, int> > request[N];
int cord[N];
void discre(int &x) { x = lower_bound(cord + 1, cord + cord[0] + 1, x) - cord; }
int tag[N << 2];
void pdw(int x) {
  if (tag[x] > -2) tag[x + x] = tag[x + x + 1] = tag[x], tag[x] = -2;
}
void paint(int x, int l, int r, int p, int q, int i) {
  if (p == l && r == q) {
    tag[x] = i;
    return;
  }
  pdw(x);
  int mid = (l + r) >> 1;
  if (q <= mid)
    paint(x + x, l, mid, p, q, i);
  else if (p > mid)
    paint(x + x + 1, mid + 1, r, p, q, i);
  else
    paint(x + x, l, mid, p, mid, i),
        paint(x + x + 1, mid + 1, r, mid + 1, q, i);
}
void walk(int x, int l, int r) {
  if (l == r) {
    if (l == cord[0] || tag[x] < 0) return;
    int p = cord[l], q = cord[l + 1];
    int fast = lower_bound(ask + 1, ask + m + 1, tag[x] - q) - ask;
    int slow = lower_bound(ask + 1, ask + m + 1, tag[x] - p) - ask;
    if (fast > m) return;
    if (slow == fast) {
      d0[slow] += q - p;
      return;
    }
    if (slow > m) {
      d0[fast] += q - tag[x];
      d1[fast]++;
      return;
    }
    d0[fast] += q - tag[x];
    d1[fast]++;
    d0[slow] -= q - tag[x];
    d1[slow]--;
    d0[slow] += q - p;
    return;
  }
  pdw(x);
  int mid = (l + r) >> 1;
  walk(x + x, l, mid);
  walk(x + x + 1, mid + 1, r);
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1, x, y, z; i <= n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    request[i] = pair<int, pair<int, int> >(z, pair<int, int>(x, y));
    cord[++cord[0]] = x;
    cord[++cord[0]] = y;
  }
  for (int i = 1; i <= m; i++) scanf("%d", &ask[i]);
  sort(request + 1, request + n + 1);
  sort(cord + 1, cord + cord[0] + 1);
  cord[0] = unique(cord + 1, cord + cord[0] + 1) - cord - 1;
  for (int i = 1; i <= n; i++) {
    discre(request[i].second.first);
    discre(request[i].second.second);
  }
  tag[1] = -1;
  for (int i = n; i; i--)
    paint(1, 1, cord[0], request[i].second.first, request[i].second.second - 1,
          request[i].first);
  walk(1, 1, cord[0]);
  for (int i = 1; i <= m; i++) {
    d0[i] += d0[i - 1];
    d1[i] += d1[i - 1];
    printf("%d\n", int(d0[i] + d1[i] * ask[i]));
  }
  return 0;
}
