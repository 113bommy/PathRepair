#include <bits/stdc++.h>
using namespace std;
const int Maxn = 755;
const int Maxm = 200005;
const long long Inf = 1000000000000005;
int n, m;
int a[Maxn];
vector<long long> ind;
vector<int> el;
int Solve(long long x) {
  int res = 0;
  priority_queue<int> Q;
  long long st = 0;
  for (int i = 0; i < n; i++) {
    st += a[i];
    Q.push(-a[i]);
    while (st + x < 0) {
      st += Q.top();
      Q.pop();
      res++;
    }
  }
  return res;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  ind.push_back(0);
  el.push_back(Solve(0));
  while (el.back() != 0) {
    long long l = ind.back() + 1, r = Inf;
    long long res;
    while (l <= r) {
      long long m = l + r >> 1ll;
      if (Solve(m) != el.back()) {
        res = m;
        r = m - 1;
      } else
        l = m + 1;
    }
    ind.push_back(res);
    el.push_back(Solve(res));
  }
  while (m--) {
    long long b;
    scanf("%I64d", &b);
    int i = upper_bound(ind.begin(), ind.end(), b) - ind.begin() - 1;
    printf("%d\n", el[i]);
  }
  return 0;
}
