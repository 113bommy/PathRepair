#include <bits/stdc++.h>
const double eps = 1e-19;
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const int MAXN = 200005;
using namespace std;
long long n, m, ans;
long long a[MAXN];
long long fact[MAXN], st[MAXN];
map<int, int> same;
long long f(int x, int nst) {
  long long res = 1;
  for (int i = 2; i <= x; i++) {
    long long t = i;
    while (nst && t % 2 == 1) {
      t /= 2;
      nst--;
    }
    res = (res * t) % m;
  }
  return res;
}
int main() {
  cin >> n;
  n *= 2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    same[a[i]] = 0;
  }
  for (int i = 0; i < n / 2; i++) {
    if (a[i] == a[i + n / 2]) same[a[i]]++;
  }
  cin >> m;
  sort(a, a + n);
  fact[0] = 1;
  st[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % m;
    st[i] = (st[i - 1] * 2) % m;
  }
  int k = 0;
  a[n] = -1;
  ans = 1;
  for (int i = 0; i < n; i++) {
    k++;
    if (a[i] != a[i + 1]) {
      ans = (ans * f(k, same[a[i]])) % m;
      k = 0;
    }
  }
  cout << ans;
  return 0;
}
