#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 1ll << 62;
const int iinf = 0x7fffffff;
long long powmod(long long a, long long b) {
  long long ans;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    b >>= 1;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; };
long long n;
long long a[1000006];
vector<long long> child;
long long ans = inf;
long long remain[1000006][15];
void get_ans(int ch) {
  long long tempans = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    tempans += min(child[ch] - remain[i][ch], remain[i][ch]);
  }
  if (tempans < ans) ans = tempans;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long sum = 0;
  memset((a), (0), sizeof(a));
  memset((remain), (0), sizeof(remain));
  cin >> n;
  for (int(i) = (0); (i) < (n); (i)++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 2; i < sqrt(sum); ++i) {
    if (sum % i == 0) {
      child.push_back(i);
      while (sum % i == 0) sum /= i;
    }
  }
  if (sum > 1) child.push_back(sum);
  sum = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    sum += a[i];
    for (int(j) = (0); (j) < (child.size()); (j)++) {
      remain[i][j] = sum % child[j];
    }
  }
  for (int(i) = (0); (i) < (child.size()); (i)++) {
    get_ans(i);
  }
  if (ans == inf)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
