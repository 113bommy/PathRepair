#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int pos[N];
struct node {
  int s, t;
  void read() { scanf("%d %d", &s, &t); }
} q[N];
int e, head[N];
int pnt[N], nxt[N];
int cnt;
int f[N];
const int mod = 1000000007;
void add(int u, int v) {
  pnt[e] = v;
  nxt[e] = head[u];
  head[u] = e++;
}
int find(int x) {
  int l = 0, r = cnt - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (pos[mid] == x) return mid;
    if (pos[mid] > x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}
int main() {
  int n, m;
  while (~scanf("%d %d", &n, &m)) {
    e = 0;
    memset(head, -1, sizeof(head));
    pos[0] = -1;
    for (int i = 1; i <= m; i++) {
      q[i].read();
      pos[(i << 1) - 1] = q[i].s;
      pos[i << 1] = q[i].t;
    }
    pos[m << 1 | 1] = 0;
    pos[(m + 1) << 1] = n;
    sort(pos, pos + (m << 1) + 3);
    cnt = 0;
    for (int i = 0; i <= ((m + 1) << 1); i++) {
      if (i == 0 || pos[i] != pos[i - 1]) {
        pos[cnt++] = pos[i];
      }
    }
    for (int i = 1; i <= m; i++) {
      int l = find(q[i].s), r = find(q[i].t);
      q[i].s = l, q[i].t = r;
      add(r, l);
    }
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < cnt; i++) {
      int sum = 0;
      for (int j = head[i]; j != -1; j = nxt[j]) {
        sum += (f[i - 1] - f[pnt[j] - 1] + (mod << 1)) % mod;
        if (sum >= mod) sum %= mod;
      }
      f[i] = f[i - 1] + sum;
      if (f[i] >= mod) f[i] %= mod;
    }
    printf("%d\n", ((f[cnt - 1] - f[cnt - 2]) % mod + mod) % mod);
  }
  return 0;
}
