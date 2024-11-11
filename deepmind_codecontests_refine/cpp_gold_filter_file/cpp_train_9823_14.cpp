#include <bits/stdc++.h>
int dr[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dc[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dr1[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc1[] = {1, -1, 1, 0, -1, 0, 1, -1};
int dr2[] = {0, 0, 1, -1};
int dc2[] = {1, -1, 0, 0};
using namespace std;
vector<long long> v;
long long len, k;
long long dp[62][65][65];
long long cal(long long x, long long y1, long long y2) {
  if (x == k) {
    if (y1 <= y2) return 1;
    return 0;
  }
  long long &r = dp[x][y1][y2];
  if (r != -1) return r;
  r = 0;
  long long i, j;
  for (i = 0; i < 2; i++) {
    if (x == 0 && i == 0) continue;
    long long ch = y1, br = y2;
    for (j = x; j < len; j += k) {
      if (v[j] > i) ch = min(ch, j);
      if (v[j] < i) br = min(br, j);
    }
    r += cal(x + 1, ch, br);
  }
  return r;
}
long long dp1[64];
long long cal1(long long x) {
  vector<long long> v1;
  long long i, j;
  for (i = 1; i < x; i++) {
    if (x % i == 0) v1.push_back(i);
  }
  long long ans = 0;
  for (i = 0; i < v1.size(); i++) {
    long long p = v1[i] - 1;
    dp1[i] = (1LL << p);
    for (j = 0; j < i; j++) {
      if (v1[i] % v1[j] == 0) dp1[i] -= dp1[j];
    }
    ans += dp1[i];
  }
  return ans;
}
long long get(long long x) {
  if (x == 0) return x;
  long long i, j;
  v.clear();
  while (x != 0) {
    long long r = x % 2;
    v.push_back(r);
    x /= 2;
  }
  len = v.size();
  reverse(v.begin(), v.end());
  vector<long long> v1;
  for (i = 1; i < len; i++)
    if (len % i == 0) v1.push_back(i);
  long long ans = 0;
  for (i = 0; i < v1.size(); i++) {
    k = v1[i];
    memset(dp, -1, sizeof(dp));
    dp1[i] = cal(0, 61, 61);
    for (j = i - 1; j >= 0; j--) {
      if (v1[i] % v1[j] == 0) dp1[i] -= dp1[j];
    }
    ans += dp1[i];
  }
  for (i = 1; i < len; i++) ans += cal1(i);
  return ans;
}
int main() {
  long long n, i, j, x, y;
  while (cin >> x >> y) {
    long long ans1 = get(x - 1);
    long long ans2 = get(y);
    cout << ans2 - ans1 << endl;
  }
  return 0;
}
