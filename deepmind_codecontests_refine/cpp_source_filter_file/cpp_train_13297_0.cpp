#include <bits/stdc++.h>
using namespace std;
inline long long Qmul(const long long &x, const long long &y,
                      const long long &X) {
  long long k = (long long)((1.0L * x * y) / (1.0L * X)), t = x * y - k * X;
  t -= X;
  while (t < 0) t += X;
  return t;
}
class MillerRabin {
 private:
  const int P[12] = {2, 3, 5, 7, 11, 13, 17, 19, 61, 2333, 4567, 24251};
  inline long long Qpow(long long x, long long y, long long X) {
    long long t = 1;
    while (y) y & 1 && (t = Qmul(t, x, X)), x = Qmul(x, x, X), y >>= 1;
    return t;
  }
  inline bool Check(const long long &x, const int &p) {
    if (!(x % p) || Qpow(p % x, x - 1, x) ^ 1) return false;
    long long k = x - 1, t;
    while (!(k & 1)) {
      if ((t = Qpow(p % x, k >>= 1, x)) ^ 1 && t ^ (x - 1)) return false;
      if (!(t ^ (x - 1))) return true;
    }
    return true;
  }

 public:
  bool IsPrime(const long long &x) {
    if (x < 2) return false;
    for (int i = 0; i ^ 12; ++i) {
      if (!(x ^ P[i])) return true;
      if (!Check(x, P[i])) return false;
    }
    return true;
  }
};
class PollardRho {
 private:
  long long ans;
  MillerRabin MR;
  inline long long gcd(const long long &x, const long long &y) {
    return y ? gcd(y, x % y) : x;
  }
  inline long long Work(const long long &x, const int &y) {
    int t = 0, k = 1;
    long long v0 = (1LL * rand() * rand() * rand() * rand() % (x - 1) + 1),
              v = v0, d, s = 1;
    while (1) {
      if (v = (Qmul(v, v, x) + y) % x,
          s = Qmul(s, ((v - v0) < 0 ? -(v - v0) : (v - v0)), x),
          !(v ^ v0) || !s)
        return x;
      if (++t == k) {
        if ((d = gcd(s, x)) ^ 1) return d;
        v0 = v, k <<= 1;
      }
    }
  }
  inline void Resolve(long long x, int t) {
    if (!(x ^ 1) || x <= ans) return;
    if (MR.IsPrime(x)) return (void)(ans < (x) && (ans = (x)));
    long long y = x;
    while ((y = Work(x, t--)) == x)
      ;
    while (!(x % y)) x /= y;
    Resolve(x, t), Resolve(y, t);
  }

 public:
  inline PollardRho() { srand(20050521); }
  inline long long GetMax(const long long &x) {
    return ans = 0, Resolve(x, 302627441), ans;
  }
} P;
int T, p, ans[10010];
long long pr[60], dis[100010], head[100010], o;
struct edge {
  int to, link;
  long long w;
} e[6000010];
struct node {
  int id;
  long long w;
  bool operator<(const node &b) const { return w > b.w; }
};
priority_queue<node> Q;
struct ask {
  long long n, k, id;
  bool operator<(const ask &b) const { return k < b.k; }
} q[10010];
void add_edge(int u, int v, long long w) {
  e[++o].to = v, e[o].link = head[u], head[u] = o, e[o].w = w;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) return x = 1, y = 0, a;
  long long t = exgcd(b, a % b, y, x);
  return y -= a / b * x, t;
}
int main() {
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) scanf("%lld%lld", &q[i].n, &q[i].k), q[i].id = i;
  sort(q + 1, q + T + 1);
  for (int l = 1, r = 0; l <= T; l = r + 1) {
    while (r < T && q[r + 1].k == q[l].k) r++;
    long long k = q[l].k;
    if (k == 1) continue;
    p = 0;
    while (k > 1) {
      pr[++p] = P.GetMax(k);
      while (k % pr[p] == 0) k /= pr[p];
    }
    if (p == 1) {
      for (int i = l; i <= r; i++) ans[q[i].id] = (q[i].n % pr[1] == 0);
      continue;
    }
    if (p == 2) {
      long long x, y;
      exgcd(pr[0], pr[1], x, y);
      x = (x % pr[1] + pr[1]) % pr[1];
      for (int i = l; i <= r; i++) {
        long long b = q[i].n - Qmul(x, q[i].n, pr[1]) * pr[0];
        ans[q[i].id] = (b >= 0);
      }
      continue;
    }
    int L = pr[p];
    o = 0;
    for (int i = 1; i < L; i++) dis[i] = LLONG_MAX;
    for (int i = 0; i < L; i++) {
      head[i] = 0;
      for (int j = 1; j < p; j++) add_edge(i, (i + pr[j]) % L, pr[j]);
    }
    Q.push((node){0, dis[0] = 0});
    while (Q.size()) {
      int u = Q.top().id;
      Q.pop();
      for (int i = head[u]; i; i = e[i].link)
        if (e[i].w + dis[u] < dis[e[i].to]) {
          dis[e[i].to] = dis[u] + e[i].w;
          Q.push((node){e[i].to, dis[e[i].to]});
        }
    }
    for (int i = l; i <= r; i++) ans[q[i].id] = (q[i].n >= dis[q[i].n % L]);
  }
  for (int i = 1; i <= T; i++) puts(ans[i] ? "YES" : "NO");
}
