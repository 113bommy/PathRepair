#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string toBin(long long a) {
  string res = "";
  while (a) {
    res += char((a & 1) + '0');
    a >>= 1;
  }
  reverse(res.begin(), res.end());
  return res;
}
const int mod = 1e9 + 7;
long long expo(long long base, long long pow) {
  long long ans = 1;
  while (pow != 0) {
    if (pow & 1 == 1) {
      ans = ans * base;
      ans = ans % mod;
    }
    base *= base;
    base %= mod;
    pow /= 2;
  }
  return ans;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
const int M = 100001;
int range[M];
int tree[5 * M];
void build(int node, int left, int right) {
  if (left == right) {
    tree[node] = left;
    return;
  }
  int mid = (left + right) / 2;
  build(2 * node, left, mid);
  build(2 * node + 1, mid + 1, right);
  if (range[tree[2 * node]] > range[tree[2 * node + 1]])
    tree[node] = tree[2 * node];
  else
    tree[node] = tree[2 * node + 1];
}
int range_q(int node, int left, int right, int qleft, int qright) {
  if (left >= qleft && right <= qright) {
    return tree[node];
  }
  if (qright < left || qleft > right || left > right) {
    return -1;
  }
  int mid = (left + right) / 2;
  int ind1 = range_q(2 * node, left, mid, qleft, qright);
  int ind2 = range_q(2 * node + 1, mid + 1, right, qleft, qright);
  if (ind1 == -1) return ind2;
  if (ind2 == -1) return ind1;
  if (range[ind1] > range[ind2]) {
    return ind1;
  } else {
    return ind2;
  }
}
int main() {
  int n;
  scanf("%d", &(n));
  memset(tree, 0, sizeof(tree));
  for (int i = 0; i < n - 1; i++) {
    int el;
    scanf("%d", &(el));
    range[i] = el - 1;
  }
  range[n - 1] = 0;
  build(1, 0, n - 1);
  long long dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[n - 1] = 0;
  long long ans = 0;
  for (int i = n - 2; i >= 0; i--) {
    int rmost = range[i];
    int m = range_q(1, 0, n - 1, i + 1, rmost);
    int one = dp[m];
    int two = range[i] - m;
    int three = n - i - 1;
    dp[i] = one - two + three;
    ans += dp[i];
  }
  cout << ans << endl;
}
