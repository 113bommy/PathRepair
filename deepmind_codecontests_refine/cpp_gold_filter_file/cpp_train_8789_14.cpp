#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
const int MAXN = 1200 * 1000;
long long a[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &a[i]);
  }
  int it1 = 0;
  int it2 = n - 1;
  long long ans = 0;
  while (it1 < it2) {
    ans += 2 * (a[it2] - a[it1]);
    it1 += m;
    it2 -= m;
  }
  cout << ans << endl;
  return 0;
}
