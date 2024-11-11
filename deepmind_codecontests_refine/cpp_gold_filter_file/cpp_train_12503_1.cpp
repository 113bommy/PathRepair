#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e7 + 5;
struct Node {
  int lc, rc;
  Node() {}
} tr[maxN];
int N;
int sz[maxN];
int totnode, root;
long long ans, T, sum;
long long Getsum(int now, long long l, long long r, long long bnd) {
  if (now == 0) return 0;
  if (r <= bnd) return sz[now];
  long long mid = l + ((r - l) >> 1);
  long long ans = Getsum(tr[now].lc, l, mid, bnd);
  if (bnd > mid) ans += Getsum(tr[now].rc, mid + 1, r, bnd);
  return ans;
}
void Insert(int& now, long long l, long long r, long long x) {
  if (now == 0) now = ++totnode;
  if (l == r) {
    sz[now]++;
    return;
  }
  long long mid = l + ((r - l) >> 1);
  if (x <= mid)
    Insert(tr[now].lc, l, mid, x);
  else
    Insert(tr[now].rc, mid + 1, r, x);
  sz[now] = sz[tr[now].lc] + sz[tr[now].rc];
}
int main() {
  scanf("%d%I64d", &N, &T);
  T--;
  Insert(root, (long long)-2e14, (long long)2e14, 0);
  for (int i = 1; i <= N; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
    int ret = Getsum(root, (long long)-2e14, (long long)2e14, T - sum);
    ans += ret;
    Insert(root, (long long)-2e14, (long long)2e14, -sum);
  }
  cout << ans << endl;
  return 0;
}
