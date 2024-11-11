#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
template <class T1, class T2, class T3, class T4>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {
  printsp(x1), printsp(x2), printsp(x3), println(x4);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int root[100011], cnt[100011];
long long ans;
long long tot[100011];
int find_root(int u) {
  if (root[u] == u) return u;
  return root[u] = find_root(root[u]);
}
void join(int u, int v, int l) {
  u = find_root(u), v = find_root(v);
  if (u == v) {
    tot[u] += l;
    return;
  }
  if (cnt[u] > cnt[v]) swap(u, v);
  root[u] = v;
  cnt[v] += cnt[u];
  tot[v] += tot[u];
  tot[v] += l;
}
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    pq;
int main() {
  int n, m, p, q;
  cin >> n >> m >> p >> q;
  for (int i = 1; i <= n; i++) root[i] = i, cnt[i] = 1;
  int su, sv;
  for (int i = 0; i < m; i++) {
    int u, v, l;
    gn(u, v, l);
    join(u, v, l);
    su = u, sv = v;
  }
  int k = 0;
  for (int i = 1; i <= n; i++)
    if (root[i] == i) k++, pq.push(pair<long long, long long>(tot[i], i));
  if (k < q or p < k - q) return puts("NO");
  if (k == q and m == 0) {
    if (p) return puts("NO");
    return puts("YES");
  }
  puts("YES");
  k -= q;
  p -= k;
  while (k--) {
    long long u = pq.top().first, uid = pq.top().second;
    pq.pop();
    long long v = pq.top().first, vid = pq.top().second;
    pq.pop();
    print(uid, vid);
    su = uid, sv = vid;
    long long add = min(1000000000ll, tot[uid] + tot[vid] + 1);
    tot[uid] += tot[vid] + add;
    pq.push(pair<long long, long long>(u, uid));
  }
  while (p--) {
    print(su, sv);
  }
  return 0;
}
