#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
inline int reint() {
  int d;
  scanf("%d", &d);
  return d;
}
inline long relong() {
  long l;
  scanf("%ld", &l);
  return l;
}
inline char rechar() {
  scanf(" ");
  return getchar();
}
inline double redouble() {
  double d;
  scanf("%lf", &d);
  return d;
}
inline string restring() {
  string s;
  cin >> s;
  return s;
}
const int maxn = 200000 + 10;
long long a[maxn], f[maxn];
int n, k;
long long past_sum;
int main(void) {
  cin.sync_with_stdio(false);
  cin >> n >> k;
  for (int i = (0); i <= (n); i++) {
    cin >> a[i];
  }
  f[n] = a[n];
  for (int i = (n - 1); i >= (0); i--) {
    if (f[i + 1] == LLONG_MAX)
      f[i] = f[i + 1];
    else {
      f[i] = f[i + 1] * 2 + a[i];
      if (fabs(f[i]) > k) {
        f[i] = LLONG_MAX;
      }
    }
  }
  int ans = 0;
  for (int i = (0); i <= (n); i++) {
    if (f[i + 1] != LLONG_MAX && fabs(past_sum + f[i + 1] * 2) <= k &&
        (i != n || past_sum + f[i + 1] * 2 != 0))
      ans++;
    past_sum += a[i];
    if (past_sum & 1) break;
    past_sum /= 2;
  }
  cout << ans << endl;
  return 0;
}
