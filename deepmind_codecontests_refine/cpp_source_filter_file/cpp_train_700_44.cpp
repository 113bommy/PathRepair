#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n;
long long a[N], b[N];
int sz;
vector<int> id[N];
long long dp[N][N];
int pass, mark[N][N];
long long f(int i, int qnt, long long k) {
  if (i == sz) return 0;
  long long &ans = dp[i][qnt];
  if (mark[i][qnt] == pass) return ans;
  mark[i][qnt] = pass;
  ans = 1e18;
  int len = id[i].size();
  if (qnt >= len) {
    ans = min(ans, f(i + 1, qnt - len, k));
  }
  long long sum = 0;
  for (int j = 0; j < len; j++) {
    sum += a[id[i][j]];
    sum -= k * b[id[i][j]];
    if (qnt >= len - (j + 1)) {
      ans = min(ans, sum + f(i + 1, qnt - len + 2 * (j + 1), k));
    }
  }
  return ans;
}
bool check(long long x) {
  pass++;
  return f(0, 0, x) <= 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i), a[i] *= 1000;
  for (int i = 0; i < n; i++) scanf("%lld", b + i);
  {
    set<long long> s;
    for (int i = 0; i < n; i++) s.insert(a[i]);
    map<long long, int> go;
    for (int x : s) go[x] = sz++;
    for (int i = 0; i < n; i++) id[sz - 1 - go[a[i]]].push_back(i);
    for (int i = 0; i < sz; i++) {
      sort(id[i].begin(), id[i].end(),
           [](int q, int w) { return b[q] < b[w]; });
    }
  }
  long long L = 1, R = 1e14, ans = 1e14;
  while (L <= R) {
    long long mid = (L + R) / 2;
    if (check(mid))
      ans = mid, R = mid - 1;
    else
      L = mid + 1;
  }
  printf("%lld\n", ans);
}
