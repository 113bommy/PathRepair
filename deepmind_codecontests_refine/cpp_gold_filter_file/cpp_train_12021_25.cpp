#include <bits/stdc++.h>
#pragma comment(linker, "/stack:102400000,102400000")
using namespace std;
int lowbit(int x) { return (x & -x); }
bool isdig(char ch) { return ch >= '0' && ch <= '9'; }
bool isup(char ch) { return ch >= 'A' && ch <= 'Z'; }
bool islow(char ch) { return ch >= 'a' && ch <= 'z'; }
template <class T_>
T_ f_abs(T_ x) {
  return x < 0 ? -x : x;
}
template <class T_>
T_ f_max(T_ a, T_ b) {
  return a > b ? a : b;
}
template <class T_>
T_ f_min(T_ a, T_ b) {
  return a < b ? a : b;
}
template <class T_>
T_ gcd(T_ a, T_ b) {
  while (T_ t = a % b) a = b, b = t;
  return b;
}
template <class T_>
void f_swap(T_ &a, T_ &b) {
  T_ t = a;
  a = b;
  b = t;
}
const double eps = 1e-10;
const int inf = 1000000007;
const int mod = 1000000007;
const int N = 1003;
int n, pre[N];
double l, x[N], b[N], dp[N];
stack<int> stk;
void init() {}
void get_data() {
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &x[i], &b[i]);
}
bool check(double mid) {
  int i, j;
  for (i = 1; i <= n; ++i) {
    pre[i] = -1;
    dp[i] = sqrt(fabs(x[i] - l)) - mid * b[i];
    for (j = 1; j < i; ++j) {
      double tmp = dp[j] + sqrt(fabs(x[i] - x[j] - l)) - mid * b[i];
      if (dp[i] > tmp) {
        dp[i] = tmp;
        pre[i] = j;
      }
    }
  }
  return (dp[n] <= eps);
}
void solve() {
  double low, high, mid;
  low = 0;
  high = inf;
  while (fabs(low - high) >= eps) {
    mid = (low + high) / 2;
    if (check(mid))
      high = mid;
    else
      low = mid;
  }
  do {
    stk.push(n);
    n = pre[n];
  } while (n != -1);
  while (!stk.empty()) {
    printf("%d ", stk.top());
    stk.pop();
  }
}
int main() {
  while (~scanf("%d%lf", &n, &l)) {
    init();
    get_data();
    solve();
  }
  return 0;
}
