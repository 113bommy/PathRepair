#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, q, ans[maxn];
char S[maxn], T[maxn];
queue<int> mat[maxn];
struct Querys {
  int pos, len, tid, x;
} Q[maxn];
const int P1 = 1e9 + 7, P2 = 1e9 + 9, B1 = 2333, B2 = 51111;
int pw1[maxn], pw2[maxn];
struct Hnode {
  int v1, v2;
  Hnode() {}
  Hnode(int x, int y) : v1(x), v2(y) {}
  Hnode app(int c) {
    return Hnode((1ll * B1 * v1 + c) % P1, (1ll * B2 * v2 + c) % P2);
  }
  long long get() { return 1ll * v1 * P2 + v2; }
} dat[maxn], A[maxn];
Hnode query(Hnode* S, int l, int r) {
  return Hnode((S[r].v1 + 1ll * (P1 - S[l - 1].v1) * pw1[r - l + 1]) % P1,
               (S[r].v2 + 1ll * (P2 - S[l - 1].v2) * pw2[r - l + 1]) % P2);
}
const int P = 1e5 + 3;
int h[P], nxt[maxn];
long long key[maxn];
int find(long long x) {
  for (int i = h[x % P]; i; i = nxt[i])
    if (key[i] == x) return i;
  return -1;
}
void ins(long long x, int id) {
  int& H = h[x % P];
  nxt[id] = H, key[id] = x, H = id;
}
int main() {
  scanf("%s%d", S + 1, &q), n = strlen(S + 1);
  for (int i = (1), iend = (q); i <= iend; ++i) {
    Q[i].pos = Q[i - 1].pos + Q[i - 1].len + 1, ans[i] = 1e9,
    scanf("%d%s", &Q[i].x, T + Q[i].pos), Q[i].tid = i,
    Q[i].len = strlen(T + Q[i].pos);
  }
  pw1[0] = pw2[0] = 1;
  for (int i = (1), iend = (n); i <= iend; ++i) A[i] = A[i - 1].app(S[i]);
  for (int i = (1), iend = (maxn - 1); i <= iend; ++i)
    pw1[i] = 1ll * B1 * pw1[i - 1] % P1, pw2[i] = 1ll * B2 * pw2[i - 1] % P2,
    dat[i] = dat[i - 1].app(T[i]);
  sort(Q + 1, Q + q + 1, [](Querys X, Querys Y) { return X.len < Y.len; });
  for (int l = (1), lend = (q); l <= lend; ++l) {
    int r = l, len = Q[l].len;
    while (r < q && Q[r + 1].len == len) r++;
    memset(h, 0, sizeof h);
    for (int i = (l), iend = (r); i <= iend; ++i) {
      ins(query(dat, Q[i].pos, Q[i].pos + len - 1).get(), i);
    }
    for (int i = (1), iend = (n - len + 1); i <= iend; ++i) {
      int id = find(query(A, i, i + len - 1).get());
      if (id == -1) continue;
      auto& V = mat[id];
      V.push(i);
      if ((int)V.size() > Q[id].x) V.pop();
      if ((int)V.size() == Q[id].x)
        ans[Q[id].tid] = min(ans[Q[id].tid], i - V.front() + len);
    }
    l = r;
  }
  for (int i = (1), iend = (q); i <= iend; ++i)
    printf("%d\n", ans[i] > n ? -1 : ans[i]);
  return 0;
}
