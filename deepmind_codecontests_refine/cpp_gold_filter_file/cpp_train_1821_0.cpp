#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2000 * 1005;
const long long INF = 8000000000;
const long long MOD = 1000000009;
const double PI = 2 * acos(0.0);
struct item {
  long long l, r, idx, w;
};
bool cmp(item a, item b) {
  if (a.l == b.l) {
    if (a.w == b.w) return a.r < b.r;
    return a.w < b.w;
  }
  return a.l < b.l;
}
bool cmp2(item a, item b) {
  if (a.r == b.r) {
    if (a.w == b.w) return a.l < b.l;
    return a.w < b.w;
  }
  return a.r < b.r;
}
bool cmp3(item a, item b) {
  if (a.l == b.l) {
    if (a.w == b.w) return a.r > b.r;
    return a.w < b.w;
  }
  return a.l > b.l;
}
long long n, m, cnt = 0, ans = 0, x, y;
long long order[MAXN], tree[4 * MAXN];
unordered_map<long long, long long> no;
item N[MAXN];
vector<long long> pq;
void clear_Tree(long long l, long long r, long long pos) {
  if (l > r)
    return;
  else if (l == r) {
    tree[pos] = 0;
    return;
  }
  tree[pos] = 0;
  long long mid = l + (r - l) / 2;
  clear_Tree(l, mid, pos * 2);
  clear_Tree(mid + 1, r, pos * 2 + 1);
  return;
}
void clear_Treee(long long l, long long r, long long pos) {
  if (l > r)
    return;
  else if (l == r) {
    tree[pos] = INF;
    return;
  }
  tree[pos] = INF;
  long long mid = l + (r - l) / 2;
  clear_Treee(l, mid, pos * 2);
  clear_Treee(mid + 1, r, pos * 2 + 1);
  return;
}
void up(long long L, long long R, long long tarr, long long tar,
        long long pos) {
  if (L > R || R < tarr || tarr < L) return;
  if (L == R) {
    tree[pos] = max(tree[pos], tar);
    return;
  }
  long long mid = L + (R - L) / 2;
  up(L, mid, tarr, tar, pos * 2);
  up(mid + 1, R, tarr, tar, pos * 2 + 1);
  tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
  return;
}
void upp(long long L, long long R, long long tarr, long long tar,
         long long pos) {
  if (L > R || R < tarr || tarr < L) return;
  if (L == R) {
    tree[pos] = min(tree[pos], tar);
    return;
  }
  long long mid = L + (R - L) / 2;
  upp(L, mid, tarr, tar, pos * 2);
  upp(mid + 1, R, tarr, tar, pos * 2 + 1);
  tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
  return;
}
long long rmq(long long l, long long r, long long L, long long R,
              long long pos) {
  if (L > R || R < l || r < L) return 0;
  if (l <= L && R <= r) return tree[pos];
  long long mid = L + (R - L) / 2;
  return max(rmq(l, r, L, mid, pos * 2), rmq(l, r, mid + 1, R, pos * 2 + 1));
}
long long rmqq(long long l, long long r, long long L, long long R,
               long long pos) {
  if (L > R || R < l || r < L) return INF;
  if (l <= L && R <= r) return tree[pos];
  long long mid = L + (R - L) / 2;
  return min(rmqq(l, r, L, mid, pos * 2), rmqq(l, r, mid + 1, R, pos * 2 + 1));
}
long long cross(long long l, long long r, long long ll, long long rr) {
  long long left = max(l, ll);
  long long right = min(r, rr);
  if (left > right) return 0;
  return right - left;
}
int main(void) {
  scanf("%I64d", &n);
  scanf("%I64d", &m);
  for (long long i0 = 1; i0 <= n; i0++) {
    scanf("%I64d", &N[i0].l);
    scanf("%I64d", &N[i0].r);
    pq.push_back(N[i0].l);
    pq.push_back(N[i0].r);
    N[i0].idx = i0;
    N[i0].w = 0;
  }
  for (long long i0 = 1; i0 <= m; i0++) {
    scanf("%I64d", &N[n + i0].l);
    scanf("%I64d", &N[n + i0].r);
    scanf("%I64d", &N[n + i0].w);
    pq.push_back(N[n + i0].l);
    pq.push_back(N[n + i0].r);
    N[n + i0].idx = i0;
  }
  sort(pq.begin(), pq.end());
  long long siz = pq.size();
  for (long long i0 = 0; i0 < siz; i0++) {
    if (cnt == siz - 1 || pq[i0] != pq[i0 + 1]) {
      order[++cnt] = pq[i0];
      no[pq[i0]] = cnt;
    }
  }
  long long maxR = -1;
  sort(N + 1, N + n + m + 1, cmp);
  for (long long i0 = 1; i0 <= n + m; i0++) {
    if (N[i0].w) {
      if (N[i0].r <= maxR) {
        if (ans < (N[i0].r - N[i0].l) * (N[i0].w)) {
          ans = (N[i0].r - N[i0].l) * (N[i0].w);
          y = N[i0].idx;
        }
      }
    } else {
      maxR = max(maxR, N[i0].r);
    }
  }
  sort(N + 1, N + n + m + 1, cmp2);
  for (long long i0 = 1; i0 <= n + m; i0++) {
    if (N[i0].w) {
      long long temp = rmq(no[N[i0].l], no[N[i0].r], 1, cnt, 1);
      temp *= N[i0].w;
      if (ans < temp) {
        ans = temp;
        y = N[i0].idx;
      }
    } else {
      up(1, cnt, no[N[i0].l], N[i0].r - N[i0].l, 1);
    }
  }
  clear_Tree(1, cnt, 1);
  for (long long i0 = 1; i0 <= n + m; i0++) {
    if (N[i0].w) {
      long long temp = rmq(1, no[N[i0].l], 1, cnt, 1) - N[i0].l;
      temp *= N[i0].w;
      if (ans < temp) {
        ans = temp;
        y = N[i0].idx;
      }
    } else {
      up(1, cnt, no[N[i0].l], N[i0].r, 1);
    }
  }
  clear_Treee(1, cnt, 1);
  sort(N + 1, N + n + m + 1, cmp3);
  for (long long i0 = 1; i0 <= n + m; i0++) {
    if (N[i0].w) {
      long long temp = N[i0].r - rmqq(no[N[i0].r], cnt, 1, cnt, 1);
      temp *= N[i0].w;
      if (ans < temp) {
        ans = temp;
        y = N[i0].idx;
      }
    } else {
      upp(1, cnt, no[N[i0].r], N[i0].l, 1);
    }
  }
  printf("%I64d\n", ans);
  if (!ans) return 0;
  long long ll, rr, ww;
  for (long long i0 = 1; i0 <= n + m; i0++) {
    if (N[i0].w && N[i0].idx == y) {
      ll = N[i0].l;
      rr = N[i0].r;
      ww = N[i0].w;
      break;
    }
  }
  for (long long i0 = 1; i0 <= n + m; i0++) {
    if (!N[i0].w) {
      long long length = cross(ll, rr, N[i0].l, N[i0].r);
      long long cost = length * ww;
      if (cost == ans) {
        x = N[i0].idx;
        break;
      }
    }
  }
  printf("%I64d %I64d\n", x, y);
  return 0;
}
