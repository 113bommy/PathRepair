#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BM(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T mdINV(T a, T M) {
  return BM(a, M - 2, M);
}
template <class T>
inline T PW(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <class T>
T stringtonumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
template <class T>
bool ISLEFT(T a, T b, T c) {
  if (((a.first.first - b.first.first) * (b.second.second - c.second.second) -
       (b.first.first - c.first.first) * (a.second.second - b.second.second)) <
      0.0)
    return 1;
  else
    return 0;
}
long long int a[200000 + 2];
int n;
long long int sum = 0;
long long int cum[200000 + 2];
long long int check(long long int in, long long int mid) {
  long long int res = sum;
  res = res - a[in] * in;
  res += a[in] * mid;
  if (mid < in) {
    long long int cu = cum[in - 1] - cum[mid - 1];
    res += cu;
  } else if (mid > in) {
    long long int cu = cum[mid] - cum[in];
    res -= cu;
  }
  return res;
}
int main() {
  scanf("%d", &n);
  cum[0] = 0;
  for (long long int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i] * i;
    cum[i] = cum[i - 1];
    cum[i] += a[i];
  }
  long long int ans = -1e18;
  for (long long int i = 1; i <= n; i++) {
    long long int lo = 1;
    long long int hi = n;
    for (long long int j = 1; j <= 100; j++) {
      long long int mid1 = (lo + (hi - lo) / 3);
      long long int mid2 = (hi - (hi - lo) / 3);
      long long int res1 = check(i, mid1);
      long long int res2 = check(i, mid2);
      if (res1 > res2) {
        hi = mid2;
      } else
        lo = mid1;
    }
    lo = max(lo - 20, 1ll);
    hi = min(hi + 20, (long long int)n);
    for (long long int j = lo; j <= hi; j++) ans = max(ans, check(i, j));
  }
  printf("%lld\n", ans);
  return 0;
}
