#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
long long perm[18];
set<long long> lu;
void gen_luck(long long x) {
  if (x > 100000000000LL) return;
  lu.insert(x);
  gen_luck(x * 10LL + 4LL);
  gen_luck(x * 10LL + 7LL);
}
int sz;
bool ud[21];
vector<int> res, val;
void get_res(int x, int k) {
  if (x <= 0) return;
  for (int y = 0; y < sz; ++y)
    if (!ud[y]) {
      if (k > perm[x - 1])
        k -= perm[x - 1];
      else {
        res.push_back(y);
        ud[y] = true;
        get_res(x - 1, k);
        break;
      }
    }
}
bool luck(int x) {
  while (x > 0) {
    if ((x % 10 != 7) && (x % 10 != 4)) return false;
    x /= 10;
  }
  return true;
}
int main() {
  gen_luck(4LL);
  gen_luck(7LL);
  perm[0] = 1LL;
  for (int x = 1; x < 15; ++x) perm[x] = perm[x - 1] * x;
  int n, ans = 0;
  long long k;
  scanf("%d%I64d", &n, &k);
  if ((n < 14) && (perm[n] < k)) {
    printf("-1\n");
    return 0;
  }
  sz = min(n, 13);
  get_res(sz, k);
  for (int x = n - sz; x < n; ++x) val.push_back(x + 1);
  for (int x = 0; x < sz; ++x) res[x] = val[res[x]];
  k = n - sz;
  for (__typeof((res).begin()) it = (res).begin(); it != (res).end(); ++it) {
    if ((lu.count(*it)) && luck(k + 1)) ++ans;
    ++k;
  }
  k = *lu.lower_bound(n - sz + 1);
  for (__typeof((lu).begin()) it = (lu).begin(); it != (lu).end(); ++it) {
    if (*it == k)
      break;
    else
      ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
