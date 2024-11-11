#include <bits/stdc++.h>
using namespace std;
const int N = 301000;
const long long All = 1e10;
inline long long read(void) {
  char ch = getchar();
  long long sum = 0;
  bool f = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = sum * 10 + ch - '0';
    ch = getchar();
  }
  if (f) sum = -sum;
  return sum;
}
int n, K;
long long Cnt[N];
struct node {
  int l, r, id;
  inline bool operator<(const node &aa) const { return this->l < aa.l; }
} A[N];
struct OP {
  int id;
  long long X;
};
vector<OP> que[N];
set<node> S;
struct Fenwick {
  long long Tr1[N], Tr2[N];
  inline int lowbit(int x) { return x & -x; }
  inline void init(void) {
    memset(Tr1, 0, sizeof(Tr1));
    memset(Tr2, 0, sizeof(Tr2));
    return;
  }
  inline void Modify(int x, long long t) {
    for (int p = x; p <= n; p += lowbit(p)) Tr1[p] += t, Tr2[p] += t * x;
    return;
  }
  inline long long Sum(int x, long long sum = 0) {
    for (int p = x; p; p -= lowbit(p)) sum += (Tr1[p] * (x + 1) - Tr2[p]);
    return sum;
  }
  inline void Modify(int l, int r, long long t) {
    Modify(l, t);
    Modify(r + 1, -t);
    return;
  }
  inline long long Query(int x, int y) {
    if (y < x) return 0;
    return Sum(y) - Sum(x - 1);
  }
} T;
inline set<node>::iterator split(int pos) {
  set<node>::iterator it = S.lower_bound((node){pos, pos, 0});
  if (it != S.end() && (*it).l == pos) return it;
  if (it == S.begin()) return it;
  --it;
  if ((*it).r <= pos) return ++it;
  node tmp1 = (node){it->l, pos, it->id}, tmp2 = (node){pos, it->r, it->id};
  S.erase(it);
  S.insert(tmp1);
  return S.insert(tmp2).first;
}
inline void update(int now) {
  int l = A[now].l, r = A[now].r;
  node tmp = (node){0, 0, 0};
  set<node>::iterator itr = split(r), itl = split(l);
  for (set<node>::iterator it = itl; it != itr; ++it)
    tmp = *it, que[now].push_back((OP){tmp.id, -(tmp.r - tmp.l)});
  S.erase(itl, itr);
  S.insert((node){l, r, now});
  que[now].push_back((OP){now, r - l});
  return;
}
inline bool check(long long Lim) {
  int L = 0, R = 1;
  long long sum = 0, nS = 0;
  for (; R <= n; ++R) {
    Cnt[R] = 0;
    for (register int i = 0; i < que[R].size(); i++) {
      OP &tmp = que[R][i];
      Cnt[tmp.id] += tmp.X;
      if (tmp.id >= L) nS += tmp.X;
    }
    while (L < R && nS - Cnt[L] >= Lim) ++L, nS -= Cnt[L - 1];
    sum += L;
  }
  return sum < K;
}
inline long long get_Ans(long long Lim) {
  T.init();
  long long sum = 0, Ans = 0;
  int L = 0, R = 1;
  for (; R <= n; ++R) {
    for (register int i = 0; i < que[R].size(); i++)
      T.Modify(1, que[R][i].id, que[R][i].X);
    while (L < R && T.Query(L + 1, L + 1) >= Lim + 1) ++L;
    sum += L;
    Ans += T.Query(1, L);
  }
  Ans += Lim * (K - sum);
  return Ans;
}
int main() {
  n = read();
  K = read();
  int dfn = 0;
  for (register int i = 1; i <= n; i++) A[i].l = read(), A[i].r = read();
  S.insert((node){(int)1e9 + 1, (int)1e9 + 1, 0});
  for (int i = 1; i <= n; i++) update(i);
  long long l = 0, r = 8;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid;
  }
  printf("%lld", get_Ans(l));
  return 0;
}
