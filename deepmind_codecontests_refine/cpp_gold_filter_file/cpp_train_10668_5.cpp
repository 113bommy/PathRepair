#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 2e5 + 10;
long long fact[N];
int cnt[N];
long long f[N];
vector<long long> v1[26], v2[26];
int a[N];
long long sum[N];
long long s;
void init() {
  fact[0] = 1;
  for (int i = 1; i < 20; i++) fact[i] = fact[i - 1] * i;
  for (int i = 1; i < N; i++) cnt[i] = cnt[i >> 1] + (i & 1);
}
inline long long getfact(int n) {
  if (n >= 20)
    return s + 1;
  else
    return fact[n];
}
int check(int a[], int n, int k, vector<long long> v[]) {
  f[0] = 0;
  for (int i = 1; i < (1 << n); i++) {
    f[i] = 0;
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) f[i] += getfact(a[j]);
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    sum[i] = 0;
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) sum[i] += a[j];
    }
    v[0].push_back(sum[i]);
  }
  for (int i = 1; i < (1 << n); i++) {
    for (int j = i; j; j = (j - 1) & i) {
      v[cnt[j]].push_back(sum[i] - sum[j] + f[j]);
    }
  }
  int ret = 0;
  for (int i = 0; i <= k; i++) {
    if (v[i].empty()) continue;
    sort(v[i].begin(), v[i].end());
    ret += upper_bound(v[i].begin(), v[i].end(), s) -
           lower_bound(v[i].begin(), v[i].end(), s);
  }
  return ret;
}
int main() {
  int n, k;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  init();
  if (n == 1) {
    int ans = 0;
    if (a[0] == s) ans++;
    if (getfact(a[0]) == s) ans++;
    cout << ans << endl;
    return 0;
  }
  long long ans = 0;
  ans += check(a, n / 2, k, v1);
  ans += check(a + n / 2, n - n / 2, k, v2);
  for (int i = 0; i <= k; i++) {
    for (auto &x : v1[i]) {
      for (int j = 0; i + j <= k; j++) {
        ans += upper_bound(v2[j].begin(), v2[j].end(), s - x) -
               lower_bound(v2[j].begin(), v2[j].end(), s - x);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
