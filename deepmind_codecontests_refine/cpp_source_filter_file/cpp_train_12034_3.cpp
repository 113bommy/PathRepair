#include <bits/stdc++.h>
using namespace std;
int upd[400000][10];
long long val[400000][10];
bool dirty[400000];
void clean(int n, int l, int r) {
  int buf[10];
  memset(buf, 0, sizeof buf);
  for (int i = 0; i < 10; i++) {
    buf[upd[n][i]] += val[n][i];
  }
  dirty[n] = false;
  for (int i = 0; i < 10; i++) {
    val[n][i] = buf[i];
  }
  if (l < r) {
    dirty[n * 2] = dirty[n * 2 + 1] = true;
    for (int i = 0; i < 10; i++) {
      upd[n * 2][i] = upd[n][upd[n * 2][i]];
      upd[n * 2 + 1][i] = upd[n][upd[n * 2 + 1][i]];
    }
  }
  for (int i = 0; i < 10; i++) {
    upd[n][i] = i;
  }
}
long long get(int rl, int rr, int n = 1, int l = 0, int r = 100000) {
  if (l > rr || r < rl) return 0;
  if (dirty[n]) clean(n, l, r);
  if (l >= rl && r <= rr) {
    long long ans = 0;
    for (int i = 0; i < 10; i++) {
      ans += val[n][i] * i;
    }
    return ans;
  }
  long long ans = get(rl, rr, n * 2, l, (l + r) / 2);
  ans += get(rl, rr, n * 2 + 1, (l + r) / 2 + 1, r);
  return ans;
}
void update(int rl, int rr, int from, int to, int n = 1, int l = 0,
            int r = 100000) {
  if (l > rr || r < rl) {
    clean(n, l, r);
    return;
  }
  if (dirty[n]) clean(n, l, r);
  if (l >= rl && r <= rr) {
    for (int i = 0; i < 10; i++) {
      if (upd[n][i] == from) upd[n][i] = to;
    }
    dirty[n] = true;
    clean(n, l, r);
    return;
  }
  update(rl, rr, from, to, n * 2, l, (l + r) / 2);
  update(rl, rr, from, to, n * 2 + 1, (l + r) / 2 + 1, r);
  for (int i = 0; i < 10; i++) {
    val[n][i] = val[n * 2][i] + val[n * 2 + 1][i];
  }
}
int n, q;
int arr[100000];
void build(int n = 1, int l = 0, int r = 100000) {
  for (int i = 0; i < 10; i++) upd[n][i] = i;
  if (l == r) {
    if (l < n) {
      int mul = 1;
      int c = arr[l];
      while (c) {
        val[n][c % 10] += mul;
        c /= 10;
        mul *= 10;
      }
    }
    return;
  }
  build(n * 2, l, (l + r) / 2);
  build(n * 2 + 1, (l + r) / 2 + 1, r);
  for (int i = 0; i < 10; i++) {
    val[n][i] = val[n * 2][i] + val[n * 2 + 1][i];
  }
}
void printtree() {
  for (int i = 0; i < n; i++) {
    cout << get(i, i) << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build();
  for (int i = 0; i < q; i++) {
    int t, l, r, x, y;
    cin >> t;
    if (t == 1) {
      cin >> l >> r >> x >> y;
      update(l - 1, r - 1, x, y);
    } else {
      cin >> l >> r;
      cout << get(l - 1, r - 1) << endl;
    }
  }
}
