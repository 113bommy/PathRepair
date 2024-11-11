#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
struct NODE {
  int l, r;
  long long val;
} tr[MAXN << 2];
long long input[MAXN], input2[MAXN];
long long cnt[MAXN], arr[MAXN], discre[MAXN], brr[MAXN];
void Push_up(long long rt) {
  tr[rt].val = tr[rt << 1].val + tr[rt << 1 | 1].val;
}
void Build(long long rt, long long l, long long r) {
  tr[rt].l = l;
  tr[rt].r = r;
  if (l == r) {
    tr[rt].val = 0;
    return;
  }
  long long mid = (l + r) >> 1;
  Build(rt << 1, l, mid);
  Build(rt << 1 | 1, mid + 1, r);
}
void Point(long long rt, long long loc) {
  if (tr[rt].l == tr[rt].r) {
    ++tr[rt].val;
    return;
  }
  long long mid = (tr[rt].l + tr[rt].r) >> 1;
  if (loc <= mid)
    Point(rt << 1, loc);
  else
    Point(rt << 1 | 1, loc);
  Push_up(rt);
}
long long Query(long long rt, long long l, long long r) {
  if (l <= tr[rt].l && tr[rt].r <= r) {
    return tr[rt].val;
  }
  long long sum = 0;
  int mid = (tr[rt].l + tr[rt].r) >> 1;
  if (mid >= l) sum += Query(rt << 1, l, r);
  if (mid < r) sum += Query(rt << 1 | 1, l, r);
  return sum;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> input[i];
    input2[i] = input[i];
  }
  sort(input2 + 1, input2 + 1 + n);
  int size = unique(input2 + 1, input2 + 1 + n) - input2 - 1;
  for (int i = 1; i <= n; ++i) {
    long long loc =
        lower_bound(input2 + 1, input2 + 1 + size, input[i]) - input2;
    discre[i] = loc;
    arr[i] = cnt[loc];
    ++cnt[loc];
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = n; i >= 1; --i) {
    brr[i] = cnt[discre[i]];
    ++cnt[discre[i]];
  }
  long long maxn = 0;
  for (int i = 1; i <= n; ++i) {
    ++arr[i];
    ++brr[i];
    maxn = max(maxn, max(arr[i], brr[i]));
  }
  Build(1, 1, n);
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += Query(1, arr[i] + 1, maxn);
    Point(1, brr[i]);
  }
  cout << ans;
}
