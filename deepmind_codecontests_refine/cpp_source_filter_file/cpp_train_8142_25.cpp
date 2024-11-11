#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
int uniform(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
const int MAXN = 900000;
const long long MOD = 1000000007;
const long long P = 101;
const long long P2 = 103;
long long power[MAXN];
long long power2[MAXN];
int n;
char word[MAXN];
long long fastExpo(long long a, long long e) {
  long long res = 1;
  while (e > 0) {
    if (e & 1LL) res = res * a % MOD;
    a = a * a % MOD;
    e >>= 1LL;
  }
  return res;
}
const long long invP = fastExpo(P, MOD - 1LL);
const long long invP2 = fastExpo(P2, MOD - 1LL);
long long soma(long long a, long long b) { return (a % MOD + b % MOD) % MOD; }
long long mult(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
long long sub(long long a, long long b) {
  return ((a % MOD - b % MOD) % MOD + MOD) % MOD;
}
struct Node {
  bool l, r;
  long long ha1, ha2, tam;
  Node(bool l_ = 0, bool r_ = 0, long long ha_ = 0, long long ha2_ = 0,
       long long t_ = 0)
      : l(l_), r(r_), ha1(ha_), ha2(ha2_), tam(t_) {}
};
Node seg[MAXN];
Node merge(Node a, Node b) {
  if (a.tam == 0) return b;
  if (b.tam == 0) return a;
  if (a.r && b.l) {
    long long aha = sub(a.ha1, mult(2LL, power[a.tam - 1]));
    long long bha = mult(power[a.tam - 1], mult(sub(b.ha1, 2LL), invP));
    long long aha2 = sub(a.ha2, mult(2LL, power2[a.tam - 1]));
    long long bha2 = mult(power2[a.tam - 1], mult(sub(b.ha2, 2LL), invP2));
    return Node(a.l && a.tam > 1, b.r && b.tam > 1, soma(aha, bha),
                soma(aha2, bha2), a.tam + b.tam - 2);
  } else {
    long long ha1 = soma(a.ha1, mult(power[a.tam], b.ha1));
    long long ha2 = soma(a.ha2, mult(power2[a.tam], b.ha2));
    return Node(a.l, b.r, ha1, ha2, a.tam + b.tam);
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
    seg[node] = Node(is1, is1, word[l] - '0' + 1, word[l] - '0' + 1, 1);
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
  power2[0] = 1;
  for (int i = 1; i < MAXN; i++)
    power[i] = power[i - 1] * P % MOD, power2[i] = power2[i - 1] * P2 % MOD;
  build();
  int m;
  scanf("%d", &m);
  int l1, l2, t;
  while (m--) {
    scanf("%d %d %d", &l1, &l2, &t);
    Node nl = query(l1 - 1, l1 - 2 + t);
    long long lq = nl.ha1;
    Node nr = query(l2 - 1, l2 - 2 + t);
    long long rq = nr.ha1;
    assert(rq == 0 || nr.tam != 0);
    assert(lq == 0 || nl.tam != 0);
    printf("%s\n", ((lq == rq) && (nl.ha2 == nr.ha2)) ? "Yes" : "No");
  }
  return 0;
}
