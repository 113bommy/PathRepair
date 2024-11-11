#include <bits/stdc++.h>
using namespace std;
int n, a[60500], des;
void read() {
  cin >> n >> des;
  for (int i = 0; i < n; ++i) cin >> a[i];
}
struct node {
  int c, to[2], s[30];
  node() {
    fill(s, s + 30, 0);
    fill(to, to + 2, 0);
    c = 0;
  }
} t[60500 * 30];
int size = 1;
void upd(int v, int x) {
  t[v].c++;
  for (int i = 0; i < 30; ++i, x >>= 1) {
    t[v].s[i] += (x & 1);
  }
}
void fill() {
  for (int i = 0; i < n; ++i) {
    int st = 0;
    for (int j = 30 - 1; j >= 0; --j) {
      int to = (a[i] >> j) & 1;
      if (t[st].to[to] == 0) t[st].to[to] = size++;
      st = t[st].to[to];
      upd(st, a[i]);
    }
  }
}
int subtreeSize(int v) {
  if (v == 0) return 0;
  return t[v].c;
}
int bigger(int val) {
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i] ^ val;
    int st = 0;
    for (int j = 30 - 1; j >= 0; --j) {
      int to = (x >> j) & 1;
      if (((val >> j) & 1) == 0) ans += subtreeSize(t[st].to[to ^ 1]);
      st = t[st].to[to];
      if (st == 0) break;
    }
    if (st != 0) ans += subtreeSize(st);
  }
  if (val == 0) ans -= n;
  return ans / 2;
}
void add(long long &ans, int x, int v) {
  if (v == 0) return;
  for (int j = 0; j < 30; ++j) {
    long long c;
    if ((x >> j) & 1)
      c = t[v].c - t[v].s[j];
    else
      c = t[v].s[j];
    ans = (ans + c * (1 << j)) % 1000000007ll;
  }
}
int sum(int val) {
  long long ans = 0, c = bigger(val) - des;
  for (int i = 0; i < n; ++i) {
    int x = a[i] ^ val;
    int st = 0;
    for (int j = 30 - 1; j >= 0; --j) {
      int to = (x >> j) & 1;
      if (((val >> j) & 1) == 0) {
        add(ans, a[i], t[st].to[to ^ 1]);
      }
      st = t[st].to[to];
      if (st == 0) break;
    }
    if (st != 0) add(ans, a[i], st);
  }
  ans = (ans * ((1000000007ll + 1) / 2)) % 1000000007ll;
  ans = (ans - c * val) % 1000000007ll;
  if (ans < 0) ans += 1000000007ll;
  return ans;
}
void bin() {
  int l = 0, r = (1 << 30) - 1, m;
  while (l < r) {
    m = (l + r) / 2;
    if (bigger(m + 1) >= des)
      l = m + 1;
    else
      r = m;
  }
  cout << sum(l) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  read();
  fill();
  bin();
  return 0;
}
