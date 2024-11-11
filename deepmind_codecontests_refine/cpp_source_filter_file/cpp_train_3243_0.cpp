#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const long long int MAX = -1000000000000000000;
const long long int MIN = 1000000000000000000;
const long long int inf = 1000000000;
const long long int KOK = 100000;
const long long int LOG = 30;
const long long int li = 100005;
const long long int mod = 1000000007;
long long int n, m, cev, b, a[li], k;
string s;
vector<long long int> v;
inline long long int solve() {
  scanf("%lld %lld %lld", &n, &b, &m);
  long long int m1 = m;
  for (long long int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long int i = 1; i <= n; i++) {
    if (m == 0 && b == 0) break;
    if (m == m1 && m > 0) {
      cev++;
      m--;
    } else if (a[i] == 1 && b > 0) {
      b--;
      m++;
      cev++;
    } else if (m > 0) {
      m--;
      cev++;
    } else {
      b--;
      cev++;
    }
  }
  printf("%lld\n", cev);
  return 0;
}
int main(void) {
  solve();
  return 0;
}
