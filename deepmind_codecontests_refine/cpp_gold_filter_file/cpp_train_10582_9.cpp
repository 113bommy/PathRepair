#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(register int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 100005;
const int M = 100005;
int n, m, nown, cnt_q, cnt_r, T;
int pos[M], col[M], ans[M];
int cnt[2 * N], sum[2 * N], a[N], lsh[N * 2];
map<int, int> mp;
struct node {
  int tim, pos, l, r;
} q[M];
int cmp(node a, node b) {
  if (a.l / T != b.l / T) {
    return a.l < b.l;
  } else if (a.r / T != b.r / T) {
    return a.r < b.r;
  } else
    return a.tim < b.tim;
}
void Add(int x) {
  sum[cnt[a[x]]]--;
  cnt[a[x]]++;
  sum[cnt[a[x]]]++;
}
void Delete(int x) {
  sum[cnt[a[x]]]--;
  cnt[a[x]]--;
  sum[cnt[a[x]]]++;
}
void modify(int x, int t) {
  if (pos[t] >= q[x].l && pos[t] <= q[x].r) {
    Delete(pos[t]);
    int tmp = a[pos[t]];
    a[pos[t]] = col[t];
    Add(pos[t]);
    a[pos[t]] = tmp;
  }
  swap(a[pos[t]], col[t]);
}
int find() {
  for (int i = 1; i <= n; i++) {
    if (sum[i] == 0) return i;
  }
}
void work() {
  sort(lsh, lsh + nown);
  int size = unique(lsh, lsh + nown) - lsh;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(lsh, lsh + size, a[i]) - lsh;
  }
  for (int i = 1; i <= cnt_r; i++) {
    col[i] = lower_bound(lsh, lsh + size, col[i]) - lsh;
  }
  return;
}
int main() {
  n = read();
  m = read();
  T = pow(n, 0.6666);
  for (int i = 1; i <= n; i++) a[i] = lsh[nown++] = read();
  for (int i = 1; i <= m; i++) {
    int t = read();
    if (t == 1) {
      cnt_q++;
      q[cnt_q].tim = cnt_r;
      q[cnt_q].pos = cnt_q;
      cin >> q[cnt_q].l >> q[cnt_q].r;
    } else {
      cnt_r++;
      cin >> pos[cnt_r] >> col[cnt_r];
      lsh[nown++] = col[cnt_r];
    }
  }
  work();
  sort(q + 1, q + cnt_q + 1, cmp);
  int cur = 0, x = 1, y = 0;
  for (int i = 1; i <= cnt_q; i++) {
    while (x < q[i].l) {
      Delete(x);
      x++;
    }
    while (x > q[i].l) {
      x--;
      Add(x);
    }
    while (y < q[i].r) {
      y++;
      Add(y);
    }
    while (y > q[i].r) {
      Delete(y);
      y--;
    }
    while (cur < q[i].tim) {
      cur++;
      modify(i, cur);
    }
    while (cur > q[i].tim) {
      modify(i, cur);
      cur--;
    }
    ans[q[i].pos] = find();
  }
  for (int i = 1; i <= cnt_q; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
