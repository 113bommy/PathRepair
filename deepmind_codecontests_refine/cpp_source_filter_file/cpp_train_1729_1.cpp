#include <bits/stdc++.h>
using namespace std;
const int MAXN = 102;
const long long INF = 1e18;
int n;
long long k;
int a[MAXN], val[MAXN];
vector<tuple<long long, int, int>> v;
long long check(int x) {
  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += ceil((double)a[i] / x);
  }
  return ret;
}
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    k += a[i];
    for (int j = 1; j * j <= a[i]; ++j) {
      int t = ceil((double)a[i] / j);
      v.push_back(make_tuple(t, j, i));
      v.push_back(make_tuple(ceil(a[i] / t), t, i));
    }
  }
  v.push_back(make_tuple(INF, -1, -1));
  sort(v.begin(), v.end());
  long long sum = 0, sol = 1;
  for (int i = 0; i < (int)v.size() - 1; ++i) {
    long long x = get<0>(v[i]), y = get<1>(v[i]), z = get<2>(v[i]);
    sum -= val[z];
    val[z] = y;
    sum += val[z];
    if (x == get<0>(v[i + 1])) continue;
    long long t = k / sum;
    sol = max(sol, (x <= t && t < get<0>(v[i + 1])) ? t : 0);
  }
  printf("%lld\n", sol);
  return 0;
}
