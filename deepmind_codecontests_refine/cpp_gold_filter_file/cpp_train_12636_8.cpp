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
int n, arr[2000003];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) arr[i] = i;
  int start = 1;
  for (int iter = 2; iter <= n; iter++) {
    int last = arr[start];
    for (int j = start + iter; j < start + n; j += iter) {
      int temp = last;
      last = arr[j];
      arr[j] = temp;
    }
    arr[start + n] = last;
    start++;
  }
  for (int i = start; i < start + n; i++) cout << arr[i] << " ";
  return 0;
}
