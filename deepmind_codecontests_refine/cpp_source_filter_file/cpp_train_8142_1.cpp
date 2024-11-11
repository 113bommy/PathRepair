#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
int uniform(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
const int MAXN = 900000;
const long long MOD = 1000000009;
const long long P = 101;
long long power[MAXN];
int n;
char word[MAXN];
long long fastExpo(long long a, long long e) {
  long long res = 1;
  while (e > 0) {
    if (e & 1) res = res * a % MOD;
    a = a * a % MOD;
    e >>= 1;
  }
  return res;
}
const long long invP = fastExpo(P, MOD - 1);
long long soma(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return (a * b) % MOD; }
long long sub(long long a, long long b) { return (a - b + MOD) % MOD; }
struct Node {
  bool l, r;
  long long ha, tam;
  Node(bool l_ = 0, bool r_ = 0, long long ha_ = 0, long long t_ = 0)
      : l(l_), r(r_), ha(ha_), tam(t_) {}
};
Node seg[MAXN];
Node merge(Node a, Node b) {
  if (a.tam == 0) return b;
  if (b.tam == 0) return a;
  if (a.r && b.l) {
    long long aha = sub(a.ha, mult(2LL, power[a.tam - 1]));
    long long bha = mult(power[a.tam - 1], mult(sub(b.ha, 2LL), invP));
    if (a.tam == 1) a.l = a.r = false;
    if (b.tam == 1) b.l = b.r = false;
    return Node(a.l, b.r, soma(aha, bha), a.tam + b.tam - 2);
  } else {
    long long ha = soma(a.ha, mult(power[a.tam], b.ha));
    return Node(a.l, b.r, ha, a.tam + b.tam);
  }
}
Node query(int ql, int qr, int node = 1, int l = 0, int r = n - 1) {
  if (qr < l || r < ql) return Node();
  if (ql <= l && r <= qr) return seg[node];
  int mid = (l + r) >> 1;
  return merge(query(ql, qr, node * 2, l, mid),
               query(ql, qr, node * 2 + 1, mid + 1, r));
}
void build(int node = 1, int l = 0, int r = n - 1) {
  if (l == r) {
    bool is1 = word[l] == '1';
    seg[node] = Node(is1, is1, word[l] - '0' + 1, 1);
  } else {
    int mid = (l + r) >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
  }
}
int main() {
  scanf("%d", &n);
  scanf("%s", word);
  power[0] = 1;
  for (int i = 1; i < MAXN; i++) power[i] = power[i - 1] * P % MOD;
  build();
  int m;
  scanf("%d", &m);
  int l1, l2, t;
  while (m--) {
    scanf("%d %d %d", &l1, &l2, &t);
    Node nl = query(l1 - 1, l1 - 2 + t);
    long long lq = nl.ha;
    Node nr = query(l2 - 1, l2 - 2 + t);
    long long rq = nr.ha;
    assert(rq == 0 || nr.tam != 0);
    assert(lq == 0 || nl.tam != 0);
    printf("%s\n", lq == rq ? "Yes" : "No");
  }
  return 0;
}
