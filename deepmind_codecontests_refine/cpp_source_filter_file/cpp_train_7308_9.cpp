#include <bits/stdc++.h>
using namespace std;
int a[200005];
int tr[200005 << 2];
long long sum[200005];
int pos[200005];
int bit[200005];
long long pre[200005];
void add(int x) {
  for (int i = x; i <= 200000; i += i & (-i)) {
    bit[i]++;
  }
}
int query(int x) {
  int sum = 0;
  for (int i = x; i > 0; i -= i & (-i)) {
    sum += bit[i];
  }
  return sum;
}
void update(int l, int r, int rt, int t) {
  if (l == r && r == t) {
    tr[rt]++;
    sum[rt] = l;
    return;
  }
  int m = (l + r) >> 1;
  if (t <= m)
    update(l, m, rt << 1, t);
  else
    update(m + 1, r, rt << 1 | 1, t);
  tr[rt] = tr[rt << 1] + tr[rt << 1 | 1];
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
int query1(int l, int r, int rt, int t) {
  if (l == r) {
    return l;
  }
  int m = (l + r) >> 1;
  if (t > tr[rt << 1 | 1])
    return query1(l, m, rt << 1, t - tr[rt << 1 | 1]);
  else
    return query1(m + 1, r, rt << 1 | 1, t);
}
long long query2(int l, int r, int rt, int t) {
  if (t == 0) return 0;
  if (l == r) {
    return sum[rt];
  }
  int m = (l + r) >> 1;
  long long ans = 0;
  if (t > tr[rt << 1 | 1])
    ans += query2(l, m, rt << 1, t - tr[rt << 1 | 1]) + sum[rt << 1 | 1];
  else
    ans += query2(m + 1, r, rt << 1 | 1, t);
  return ans;
}
void work() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = i - query(pos[i]) - 1;
    add(pos[i]);
  }
  for (int i = 1; i <= n; i++) {
    pre[i] += pre[i - 1];
  }
  printf("0");
  update(1, n, 1, pos[1]);
  long long sum = pos[1];
  for (int i = 2; i <= n; i++) {
    long long tmp = pre[i];
    update(1, n, 1, pos[i]);
    sum += pos[i];
    int mid = (i + 1) / 2;
    int p = query1(1, n, 1, mid);
    tmp += query2(1, n, 1, mid) - 1ll * (p + p + mid - 1) * (mid) / 2;
    tmp += 1ll * (p - 1 + p - i + mid) * (i - mid) / 2 -
           (sum - query2(1, n, 1, mid));
    printf(" %lld", tmp);
  }
  printf("\n");
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  T = 1;
  while (T--) {
    work();
  }
}
