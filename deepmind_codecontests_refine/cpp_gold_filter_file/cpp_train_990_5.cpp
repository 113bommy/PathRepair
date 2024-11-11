#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int n, arr[1000001], a, b;
vector<int> p;
void doit(int x) {
  long long y = 2;
  while (y * y <= x) {
    int cnt = 0;
    while (x % y == 0) x /= y, cnt++;
    if (cnt) p.push_back(y);
    y++;
  }
  if (x > 1) p.push_back(x);
}
long long dp[1000001][3], d, inf = 1ll << 58;
long long rec(int p, int s) {
  if (p == n) return 0;
  if (~dp[p][s]) return dp[p][s];
  long long ret = inf;
  if (s == 0) {
    ret = rec(p + 1, 1) + a;
    long long tmp = rec(p + 1, 0);
    int need = arr[p] % d;
    if (need == 0) {
      ret = min(ret, tmp);
    } else if (need == 1 || need == d - 1) {
      tmp += b;
      ret = min(ret, tmp);
    }
  } else if (s == 1) {
    ret = rec(p + 1, 1) + a;
    long long tmp = rec(p + 1, 2);
    int need = arr[p] % d;
    if (need == 0) {
      ret = min(ret, tmp);
    } else if (need == 1 || need == d - 1) {
      tmp += b;
      ret = min(ret, tmp);
    }
  } else {
    long long tmp = rec(p + 1, 2);
    int need = arr[p] % d;
    if (need == 0) {
      ret = min(ret, tmp);
    } else if (need == 1 || need == d - 1) {
      tmp += b;
      ret = min(ret, tmp);
    }
  }
  return dp[p][s] = ret;
}
int main() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  doit(arr[0]);
  doit(arr[0] - 1);
  doit(arr[0] + 1);
  doit(arr[n - 1]);
  doit(arr[n - 1] - 1);
  doit(arr[n - 1] + 1);
  sort((p).begin(), (p).end());
  (p).resize(unique((p).begin(), (p).end()) - (p).begin());
  long long ans = 1ll << 60;
  for (int i = 0; i < p.size(); i++) {
    memset((dp), (-1), sizeof(dp));
    d = p[i];
    ans = min(ans, rec(0, 0));
  }
  cout << ans << endl;
  return 0;
}
