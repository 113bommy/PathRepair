#include <bits/stdc++.h>
using namespace std;
long long sum1d(vector<int>& v, int st, int& l, int& r) {
  int n = (int)v.size();
  vector<long long> dp(n, 0);
  vector<int> back(n, -1);
  long long m = 0;
  l = n;
  r = n - 1;
  for (int i = st; i < n; i++) {
    if (i > st && dp[i - 1] > 0) {
      back[i] = back[i - 1];
    } else {
      back[i] = i;
    }
    dp[i] = max(i > st ? dp[i - 1] : 0ll, 0ll) + v[i];
    if (dp[i] > m) {
      l = back[i];
      r = i;
      m = dp[i];
    }
  }
  return m;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  long long s = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    s += v[i];
  }
  long long ans = 0;
  long long ps = 0;
  int a1, a2, a3;
  for (int i = 0; i < n; i++) {
    int l = -1;
    int r = -1;
    long long x = sum1d(v, i, l, r);
    long long c = ps + x - (s - ps - x);
    if (c >= ans) {
      a1 = i;
      a2 = l;
      a3 = r + 1;
      ans = c;
    }
    ps += v[i];
  }
  printf("%d %d %d\n", a1, a2, a3);
  return 0;
}
