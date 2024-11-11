#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10, Mod = 1e9 + 7;
long long n, A[maxn], p[maxn], tmp, tmp1, tmp2, tmp3, k, ans1, ans2, mx;
vector<long long> v;
long long poww(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  tmp1 = poww(x, y / 2);
  tmp1 = (tmp1 * tmp1) % Mod;
  if (y % 2) tmp1 = (tmp1 * x) % Mod;
  return tmp1;
}
long long solve(long long x) {
  v.clear();
  ans1 = 1;
  for (long long i = 1; i * i < x; i++) {
    if (x % i == 0) {
      v.push_back(i);
      v.push_back(x / i);
    }
    tmp2 = i;
  }
  tmp2++;
  if (tmp2 * tmp2 == x) v.push_back(tmp2);
  sort(v.begin(), v.end());
  for (long long i = 1; i < v.size(); i++) {
    ans1 = (ans1 * poww(i, p[v[i] - 1] - p[v[i - 1] - 1])) % Mod;
  }
  ans1 = (ans1 * (poww(v.size(), p[mx] - p[x - 1]) -
                  poww(v.size() - 1, p[mx] - p[x - 1]))) %
         Mod;
  return ans1;
}
int32_t main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
    mx = max(mx, A[i]);
    p[A[i]]++;
  }
  for (long long i = 1; i < maxn; i++) {
    p[i] = (p[i] + p[i - 1]);
  }
  for (long long i = 1; i <= mx; i++) {
    ans2 = (ans2 + solve(i)) % Mod;
  }
  cout << ans2;
  return 0;
}
