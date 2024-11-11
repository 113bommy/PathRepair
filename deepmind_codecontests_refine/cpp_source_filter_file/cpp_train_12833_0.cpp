#include <bits/stdc++.h>
using namespace std;
inline void PrintArrInt(int arr[], int s, int e) {
  for (int i = (s); i <= (e); i++) printf("%d%c", arr[i], i == e ? '\n' : ' ');
}
const int maxn = 100000 + 5;
const int mod = 1e9 + 7;
int N, Q, mxsqn, arr[maxn], lpos[maxn * 2];
struct Node {
  int ls, rs;
  long long mulv;
  Node() { mulv = 1; }
} ns[maxn * 32];
int ncnt, root[maxn];
long long _pow(long long a, long long b) {
  long long t = a, ans = 1;
  while (b) {
    if (b & 1) ans = ans * t % mod;
    t = t * t % mod;
    b >>= 1;
  }
  return ans;
}
void update(int& now, int L, int R, int pos, int val) {
  ns[++ncnt] = ns[now];
  now = ncnt;
  Node& n = ns[now];
  n.mulv = 1ll * n.mulv * val % mod;
  if (L == R) return;
  int mid = (L + R) >> 1;
  if (pos <= mid)
    update(n.ls, L, mid, pos, val);
  else
    update(n.rs, mid + 1, R, pos, val);
}
int query(int now, int L, int R, int lft, int rht) {
  if (L >= lft && R <= rht) return ns[now].mulv;
  int mid = (L + R) >> 1;
  if (rht <= mid)
    return query(ns[now].ls, L, mid, lft, rht);
  else if (lft > mid)
    return query(ns[now].rs, mid + 1, R, lft, rht);
  else
    return 1ll * query(ns[now].ls, L, mid, lft, rht) *
           query(ns[now].rs, mid + 1, R, lft, rht) % mod;
}
struct RMQ {
  int arr[maxn];
  char dp[maxn][18];
  void rmq_init() {
    for (int i = (1); i <= (N); i++) dp[i][0] = arr[i];
    for (int p = 1; (1 << p) <= N; p++) {
      for (int i = 1; i + (1 << p) - 1 <= N; i++) {
        dp[i][p] = max(dp[i][p - 1], dp[i + (1 << (p - 1))][p - 1]);
      }
    }
  }
  int rmq_query(int L, int R) {
    int logl = log2(R - L + 1);
    return max(dp[L][logl], dp[R - (1 << logl) + 1][logl]);
  }
} rmqs[90];
int flag[450], p[450], cnt;
void init() {
  for (int i = (2); i <= (449); i++) {
    if (!flag[i]) p[++cnt] = i;
    for (int j = 1; j <= cnt && i * p[j] < 450; j++) {
      flag[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}
inline void reduce(int n) {
  for (int i = 1; i <= cnt && p[i] <= mxsqn; i++) {
    while (arr[n] % p[i] == 0) rmqs[i].arr[n]++, arr[n] /= p[i];
  }
}
int main() {
  init();
  int maxv = 0;
  scanf("%d", &(N));
  for (int i = (1); i <= (N); i++)
    scanf("%d", &(arr[i])), maxv = max(maxv, arr[i]);
  mxsqn = sqrt(maxv) + 1;
  for (int i = (1); i <= (N); i++) reduce(i);
  for (int i = (1); i <= (89); i++) rmqs[i].rmq_init();
  for (int i = (1); i <= (N); i++) {
    root[i] = root[i - 1];
    if (arr[i] == 1) continue;
    if (lpos[arr[i]])
      update(root[i], 1, N, lpos[arr[i]], _pow(arr[i], mod - 2));
    update(root[i], 1, N, i, arr[i]);
    lpos[arr[i]] = i;
  }
  scanf("%d", &(Q));
  int x, y;
  long long las = 0;
  for (int i = (1); i <= (Q); i++) {
    scanf("%d%d", &(x), &(y));
    int L = (las + x) % N + 1, R = (las + y) % N + 1;
    if (L > R) swap(L, R);
    long long t1 = query(root[R], 1, N, L, R);
    long long t2 = 1;
    for (int i = (1); i <= (89); i++) {
      t2 = t2 * _pow(p[i], rmqs[i].rmq_query(L, R)) % mod;
    }
    printf("%lld\n", (las = t1 * t2 % mod));
  }
  return 0;
}
