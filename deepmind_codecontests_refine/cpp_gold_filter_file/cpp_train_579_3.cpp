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
long long int h, w, a, b, n;
long long int ar[100000 + 2];
long long int mul[100000 + 2];
long long int dp[42][200000][2];
long long int go(long long int i, long long int m, bool fl) {
  long long int first = m;
  long long int co = mul[i + 1] / m;
  if (fl) swap(first, co);
  if (first * h >= a && co * w >= b) return (n - i);
  if (i == 0) {
    return 100000 * 100;
  }
  long long int &ret = dp[i][m][fl];
  if (ret != -1) return ret;
  ret = 100000 * 100;
  if (fl == 1) {
    if (m * ar[i] * w >= b)
      return (n - i + 1);
    else
      ret = min(ret, go(i - 1, m * ar[i], 1));
  } else if (co * w >= b) {
    if (first * ar[i] * h >= a)
      return (n - i + 1);
    else
      ret = min(ret, go(i - 1, m * ar[i], 0));
  } else {
    long long int xo = m * ar[i];
    if (xo * h >= a)
      ret = min(ret, go(i - 1, co, 1));
    else
      ret = min(ret, go(i - 1, xo, 0));
    ret = min(ret, go(i - 1, m, 0));
  }
  return ret;
}
int main() {
  scanf("%lld%lld", &a, &b);
  scanf("%lld%lld", &h, &w);
  scanf("%lld", &n);
  for (long long int i = 1; i <= n; i++) scanf("%lld", &ar[i]);
  if (h >= a && w >= b) {
    printf("%d", 0), printf("\n");
    return 0;
  }
  sort(ar + 1, ar + n + 1);
  int first = max(1, (int)n - 40);
  int l = 0;
  for (int i = first; i <= n; i++) {
    ar[i - first + 1] = ar[i];
    ++l;
  }
  n = l;
  mul[n + 1] = 1;
  for (int i = n; i >= 1; i--) mul[i] = mul[i + 1] * ar[i];
  memset(dp, -1, sizeof dp);
  int ans = 0;
  int fl = 0;
  if (h >= a) fl = 1;
  ans = go(l, 1, fl);
  swap(a, b);
  memset(dp, -1, sizeof dp);
  fl = 0;
  if (h >= a) fl = 1;
  ans = min(ans, (int)go(l, 1, fl));
  if (ans > n) ans = -1;
  printf("%d", ans), printf("\n");
  return 0;
}
