#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200055];
int pos[200055];
vector<int> buf[200055];
struct o9 {
  int l;
  int id;
};
vector<o9> q[200055];
long long res[200055];
long long dat[400055];
inline long long query(int id) {
  long long res = 0ll;
  id += n;
  for (; id > 0; id >>= 1) {
    res += dat[id];
  }
  return res;
}
inline void update(int l, int r, long long val) {
  l += n, r += n;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) dat[l++] += val;
    if (r & 1) dat[--r] += val;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    q[y].push_back((o9){x, i});
  }
  for (int i = 0; i < n; i++) {
    for (auto u : buf[a[i]]) {
      update(0, u + 1, 1);
    }
    for (int j = a[i]; j <= n; j += a[i]) {
      if (pos[j] <= i) {
        update(0, pos[j] + 1, 1);
      } else {
        buf[j].push_back(i);
      }
    }
    for (auto p : q[i]) {
      res[p.id] = query(p.l);
    }
  }
  for (int i = 0; i < m; i++) printf("%lld\n", res[i]);
  return 0;
}
