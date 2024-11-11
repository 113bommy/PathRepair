#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int sum, suf, pre, max;
} Node;
int toint(const string &s) {
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
const int MAXN = 2e5 + 100;
const int UP = 31;
const long long int highest = 1e18;
const double pi = acos(-1);
const double Phi = 1.618033988749894;
const int logn = 20;
const double root5 = 2.236067977;
const int mod = 1e9 + 7;
const int ini = -1e9;
const int inf = 1e9;
const int N = 2e5 + 100;
int sg[N];
long long int fac[N];
long long int iv[N];
long long int add_s(long long int a, long long int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
long long int sub_s(long long int a, long long int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
long long int mul(long long int a, long long int b) {
  return a * 1LL * b % mod;
}
long long int bp(long long int a, long long int p) {
  if (p == 0)
    return 1LL;
  else if (p & 1)
    return mul(a, bp(mul(a, a), p >> 1));
  else
    return bp(mul(a, a), p >> 1);
}
long long int ncr(int n, int r) {
  long long int ret = fac[n];
  ret = mul(ret, iv[n - r]);
  ret = mul(ret, iv[r]);
  return ret;
}
int main() {
  fac[0] = iv[0] = 1;
  int co = 0, cur = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = mul(fac[i - 1], i);
    if (i >= 2) {
      sg[i] = cur;
      co++;
      if (co == 2) {
        cur = !cur;
        co = 0;
      }
    }
    iv[i] = bp(fac[i], mod - 2);
  }
  int n;
  scanf("%d", &n);
  int nn = n;
  std::vector<long long int> arr(n);
  std::vector<long long int> barr(n - 1);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << (arr[0]) << "\n";
    return 0;
  }
  if (n & 1) {
    for (int i = 0; i < n - 1; i++) {
      if (i % 2 == 0) {
        barr[i] = (arr[i] + arr[i + 1]);
      } else {
        barr[i] = (arr[i] - arr[i + 1]);
      }
      while (barr[i] < 0) barr[i] += mod;
    }
    arr = barr;
    n--;
  }
  long long int m = (n / 2) - 1;
  std::vector<long long int> fin(2, 0);
  for (int i = 0; i < 2; ++i) {
    for (int j = i, k = 0; j < n; j += 2, k++) {
      long long int tmp = mul(ncr(m, k), arr[j]);
      fin[i] = add_s(fin[i], tmp);
    }
  }
  long long int ans = 0;
  if (sg[nn] == 1) {
    ans = fin[0] + fin[1];
  } else {
    ans = sub_s(fin[0], fin[1]);
  }
  cout << (ans % mod) << "\n";
  return 0;
}
