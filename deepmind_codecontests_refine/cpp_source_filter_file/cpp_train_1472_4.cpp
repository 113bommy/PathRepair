#include <bits/stdc++.h>
using namespace std;
int N, m;
int a[200005], b[200005];
struct Node {
  int l, r;
  long long n, d, tag;
  Node *ls, *rs;
} pool[3 * 200005];
int top = 0;
long long getD(Node* p) {
  if (!p) return 0;
  return (p->d + p->tag * p->n % 998244353) % 998244353;
}
long long getN(Node* p) {
  if (!p) return 0;
  return p->n;
}
Node* buildT(int l, int r) {
  Node* p = pool + (++top);
  p->l = l;
  p->r = r;
  if (l == r) {
    p->d = 0;
    p->n = (b[l] == -1);
    return p;
  }
  int mid = (l + r) / 2;
  p->ls = buildT(l, mid);
  p->rs = buildT(mid + 1, r);
  p->n = getN(p->ls) + getN(p->rs);
  p->d = 0;
  return p;
}
void pushD(Node* p) {
  if (!p->tag) return;
  p->d = (p->d + p->tag * p->n % 998244353) % 998244353;
  p->ls->tag = (p->ls->tag + p->tag) % 998244353;
  p->rs->tag = (p->rs->tag + p->tag) % 998244353;
  p->tag = 0;
  return;
}
void change(Node* p, int l, int r, int k) {
  if (l > r) return;
  if (p->n == 0) return;
  if (p->l == l && p->r == r) {
    p->tag += k;
    return;
  }
  pushD(p);
  int mid = (p->l + p->r) / 2;
  if (r <= mid)
    change(p->ls, l, r, k);
  else if (l >= mid + 1)
    change(p->rs, l, r, k);
  else {
    change(p->ls, l, mid, k);
    change(p->rs, mid + 1, r, k);
  }
  p->d = (getD(p->ls) + getD(p->rs)) % 998244353;
  return;
}
long long query(Node* p, int l, int r) {
  if (p->n == 0) return 0;
  if (p->l == l && p->r == r) {
    return getD(p);
  }
  pushD(p);
  int mid = (p->l + p->r) / 2;
  if (r <= mid)
    return query(p->ls, l, r);
  else if (l >= mid + 1)
    return query(p->rs, l, r);
  else {
    long long ans =
        (query(p->ls, l, mid) + query(p->rs, mid + 1, r)) % 998244353;
    return ans;
  }
}
int fw[200005];
int lbt(int x) { return x & (-x); }
void update(int x, int dv) {
  for (; x <= N; x += lbt(x)) {
    fw[x] += dv;
  }
}
int getsum(int x) {
  int ans = 0;
  for (; x > 0; x -= lbt(x)) {
    ans += fw[x];
  }
  return ans;
}
long long qpow(long long x, long long n) {
  if (n == 1) return x;
  long long t = qpow(x, n / 2);
  if (n % 2 == 0)
    return t * t % 998244353;
  else
    return t * t % 998244353 * x % 998244353;
}
long long ans = 0;
int main() {
  ios::sync_with_stdio(0);
  cin >> N;
  memset(b, -1, sizeof(b));
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    if (a[i] == -1)
      ++m;
    else
      b[a[i]] = 0;
  }
  for (int i = N; i >= 1; i--) {
    if (a[i] != -1) {
      int x = a[i];
      ans = (ans + getsum(x - 1)) % 998244353;
      update(x, 1);
    }
  }
  Node* rt = buildT(1, N);
  for (int i = 1; i <= N; i++) {
    if (a[i] != -1) {
      change(rt, 1, a[i] - 1, 1);
    } else {
      ans = (ans + query(rt, 1, N) * qpow(m, 998244353 - 2) % 998244353) %
            998244353;
    }
  }
  memset(pool, 0, sizeof(pool));
  top = 0;
  rt = buildT(1, N);
  for (int i = N; i >= 1; i--) {
    if (a[i] != -1) {
      change(rt, a[i] + 1, N, 1);
    } else {
      ans = (ans + query(rt, 1, N) * qpow(m, 998244353 - 2) % 998244353) %
            998244353;
    }
  }
  ans = (ans + m * (m - 1) % 998244353 * qpow(4, 998244353 - 2) % 998244353) %
        998244353;
  cout << ans << endl;
  return 0;
}
