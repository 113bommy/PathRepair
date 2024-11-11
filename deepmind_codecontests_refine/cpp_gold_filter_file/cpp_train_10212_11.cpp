#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[400100];
long long m;
long long tree[400100];
long long lowbit(long long x) { return x & -x; }
void ins(long long pos, long long val) {
  for (; pos <= 400005; pos += lowbit(pos)) tree[pos] += val;
}
long long query(long long pos) {
  long long sum = 0;
  for (; pos; pos -= lowbit(pos)) sum += tree[pos];
  return sum;
}
long long cal(long long x) {
  long long ret = 0;
  memset(tree, 0, sizeof(tree));
  ins(0 + 200005, 1);
  long long cur = 0;
  for (long long i = 1; i <= n; ++i) {
    if (a[i] < x)
      cur -= 1;
    else
      cur += 1;
    ret += query(cur - 1 + 200005);
    ins(cur + 200005, 1);
  }
  return ret;
}
int main() {
  scanf("%lld %lld", &n, &m);
  for (long long i = 1; i <= n; ++i) scanf("%lld", a + i);
  printf("%lld\n", cal(m) - cal(m + 1));
  return 0;
}
