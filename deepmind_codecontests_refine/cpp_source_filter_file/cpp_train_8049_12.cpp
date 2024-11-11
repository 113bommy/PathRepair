#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int inf = 0x7FFFFFFF;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
int a[50000], b[20005];
int stk[20000];
int main() {
  int n;
  while (cin >> n) {
    int cnt = 0;
    int k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        k = i;
        if (k >= 3) stk[cnt++] = n / k;
        k = n / i;
        if (k >= 3) stk[cnt++] = n / k;
      }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
      int &mod = stk[i];
      memset(b, 0, sizeof(b));
      for (int j = 0; j < n; j++) b[j % mod] += a[j];
      for (int j = 0; j < mod; j++) checkmax(ans, b[j]);
    }
    cout << ans << endl;
  }
  return 0;
}
