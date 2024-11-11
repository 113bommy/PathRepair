#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
long long tree[200200 * 4] = {0};
long long lazy[200200 * 4] = {0};
void updateRangeUtil(long long si, long long ss, long long se, long long us,
                     long long ue, long long diff) {
  if (lazy[si] != 0) {
    tree[si] += (se - ss + 1) * lazy[si];
    if (ss != se) {
      lazy[si * 2 + 1] += lazy[si];
      lazy[si * 2 + 2] += lazy[si];
    }
    lazy[si] = 0;
  }
  if (ss > se || ss > ue || se < us) return;
  if (ss >= us && se <= ue) {
    tree[si] += (se - ss + 1) * diff;
    if (ss != se) {
      lazy[si * 2 + 1] += diff;
      lazy[si * 2 + 2] += diff;
    }
    return;
  }
  long long mid = (ss + se) / 2;
  updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
  updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
  tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}
void updateRange(long long n, long long us, long long ue, long long diff) {
  updateRangeUtil(0, 0, n - 1, us, ue, diff);
}
long long getSumUtil(long long ss, long long se, long long qs, long long qe,
                     long long si) {
  if (lazy[si] != 0) {
    tree[si] += (se - ss + 1) * lazy[si];
    if (ss != se) {
      lazy[si * 2 + 1] += lazy[si];
      lazy[si * 2 + 2] += lazy[si];
    }
    lazy[si] = 0;
  }
  if (ss > se || ss > qe || se < qs) return 0;
  if (ss >= qs && se <= qe) return tree[si];
  long long mid = (ss + se) / 2;
  return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
         getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}
long long getSum(long long n, long long qs, long long qe) {
  return getSumUtil(0, n - 1, qs, qe, 0);
}
int main() {
  long long n = 200020;
  long long N;
  cin >> N;
  long long R = 1;
  while (N--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, a;
      scanf("%d%d", &a, &x);
      updateRange(n, 0, a - 1, x);
    } else if (t == 2) {
      long long k;
      scanf("%I64d", &k);
      updateRange(n, R, R, k);
      R++;
    } else {
      long long temp = getSum(n, R - 1, R - 1);
      updateRange(n, R - 1, R - 1, -temp);
      R--;
    }
    printf("%.6lf\n", (double)getSum(n, 0, R - 1) / (double)R);
  }
  return 0;
}
