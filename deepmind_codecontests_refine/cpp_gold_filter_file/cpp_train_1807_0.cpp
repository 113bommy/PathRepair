#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
inline void read(int *a, int n) {
  for (int i = 0; i < n; i++) a[i] = in();
}
template <class blank>
inline void out(blank x) {
  cout << x << "\n";
  exit(0);
}
template <class blank>
inline void smin(blank &a, blank b) {
  a = min(a, b);
}
template <class blank>
inline void smax(blank &a, blank b) {
  a = max(a, b);
}
const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;
const int maxlg = 21;
const int base = 29;
const int mod = 1e9 + 7;
const long long inf = 2e18 + 10;
const int SQ = 317;
int32_t main() {
  int n = in();
  if (n >= 54000)
    cout << 1 << "\n";
  else if (n <= 50000)
    cout << 3 << "\n";
  else
    cout << 2 << "\n";
}
