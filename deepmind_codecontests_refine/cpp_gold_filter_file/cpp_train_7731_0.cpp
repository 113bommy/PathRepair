#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > matmul(vector<vector<long long> > &a,
                                  vector<vector<long long> > &b) {
  int i, j, k, n = a.size();
  vector<vector<long long> > ans(n, vector<long long>(n));
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      long long temp = 0;
      for (k = 0; k < n; k++)
        temp = (temp + a[i][k] * b[k][j]) % (1000000007LL);
      ans[i][j] = temp;
    }
  return ans;
}
vector<vector<long long> > matpwr(vector<vector<long long> > &a, long long p) {
  int n = a.size();
  vector<vector<long long> > ans(n, vector<long long>(n));
  for (int i = 0; i < n; i++) ans[i][i] = 1;
  while (p) {
    if (p & 1) ans = matmul(ans, a);
    a = matmul(a, a);
    p >>= 1;
  }
  return ans;
}
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long invMod(long long n, long long mod = (1000000007LL)) {
  return pwr(n, mod - 2);
}
int n, arr[105];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int tot = 0, ans = 0;
  for (int i = 0; i < n && tot + arr[i] <= 710; i++) {
    ans++;
    tot += arr[i];
  }
  cout << ans << " ";
  int pos = -1;
  tot = 10;
  for (int i = 0; i < n && tot + arr[i] <= 360; i++) {
    pos = i;
    tot += arr[i];
  }
  int cost = 0;
  for (int i = pos + 1; i < ans; i++) {
    tot += arr[i];
    cost += abs(tot - 360);
  }
  cout << cost;
  return 0;
}
