#include <bits/stdc++.h>
using namespace std;
int mod = 10000007;
long long pwr(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long temp = pwr(a, b / 2, mod);
  temp = (temp * temp) % mod;
  if (b & 1) temp = (temp * a) % mod;
  return temp;
}
long long pwr(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = pwr(a, b / 2);
  temp = (temp * temp);
  if (b & 1) temp = (temp * a);
  return temp;
}
bool *isPrime;
void generatePrimeSieve(const int lim) {
  isPrime = (bool *)malloc(lim + 1);
  memset(isPrime, true, lim + 1);
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i <= lim; ++i)
    if (isPrime[i])
      for (int j = i + i; j <= lim; j += i) isPrime[j] = false;
}
vector<vector<int> > identityMatrix;
vector<vector<int> > mul(const vector<vector<int> > &a,
                         const vector<vector<int> > &b) {
  int n = a.size();
  vector<vector<int> > ans(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        ans[i][j] += ((long long)a[i][k] * b[k][j]) % mod;
        ans[i][j] %= mod;
      }
    }
  }
  return ans;
}
vector<vector<int> > pwr(const vector<vector<int> > &a, long long n) {
  if (n == 0) {
    assert(false);
    return identityMatrix;
  }
  if (n == 1) return a;
  vector<vector<int> > tmp = pwr(a, n / 2);
  tmp = mul(tmp, tmp);
  if (n & 1) tmp = mul(a, tmp);
  return tmp;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long modularInverse(long long a, long long m) { return pwr(a, m - 2, m); }
char s[100005];
int n;
int lps[100005];
int cnt[100005];
bool start[100005];
int main() {
  scanf("%s", s);
  n = strlen(s);
  lps[0] = 0;
  for (int i = 1; i < n; ++i) {
    int j = lps[i - 1];
    while (j > 0 && s[i] != s[j]) j = lps[j - 1];
    if (s[i] == s[j]) j++;
    lps[i] = j;
    cnt[j]++;
  }
  int temp2;
  int ans = 0;
  int j = n;
  while (j) {
    start[j] = true;
    j = lps[j - 1];
    ans++;
  }
  for (int i = 0; i < n; ++i) {
    if (lps[j]) cnt[lps[j]]++;
  }
  for (int i = n; i >= 1; --i) {
    if (lps[i - 1]) cnt[lps[i - 1]] += cnt[i];
  }
  printf("%d\n", ans);
  for (int i = 0; i <= n; ++i) {
    if (start[i]) {
      printf("%d %d\n", i, cnt[i] + 1);
    }
  }
}
