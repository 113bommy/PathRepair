#include <bits/stdc++.h>
using namespace std;
const int N = 200015;
int a[N], g[N];
bool good[N];
vector<int> divp;
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
int main() {
  int n;
  while (~scanf("%d", &n)) {
    divp.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i)
      if (n % i == 0) {
        divp.push_back(i);
      }
    g[0] = 0;
    for (int i = 1; i <= n; ++i) {
      g[i] = gcd(i, n);
    }
    long long ans = 0;
    for (int i = 0; i < divp.size(); ++i) {
      int s = divp[i];
      for (int j = 0; j < n; ++j) good[j] = 0;
      for (int j = 0; j < s; ++j) {
        int maxv = 0;
        for (int p = j; p < n; p += s) {
          maxv = max(a[p], maxv);
        }
        for (int p = j; p < n; p += s) {
          if (a[p] == maxv) {
            good[p] = true;
          }
        }
      }
      int nn = 2 * n, L = 0, accm = 0;
      bool beg = good[n - 1] ? true : false;
      for (int p = 0; p < nn; ++p) {
        int j = p >= n ? p - n : p;
        if (good[j]) {
          L++;
          if (g[L] == s) ++accm;
        } else {
          L = 0;
          accm = 0;
          beg = false;
          if (p >= n - 1) break;
        }
        if (L >= n) break;
        if (!beg) ans += accm;
      }
      if (beg) {
        ans = 1LL * (n - 1) * n;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
