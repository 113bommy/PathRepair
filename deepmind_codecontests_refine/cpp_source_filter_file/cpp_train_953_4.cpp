#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int mod = (int)1e9 + 7;
const int N = 1e5 + 10;
const long long inf = -1e17;
struct event {
  long long a, b, c, d;
};
void solve() {
  long long n, bit;
  cin >> n >> bit;
  vector<int> a(n);
  long long k = 8 * bit;
  k = k / n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long z = k;
  while (z--) {
    k = k * 2LL;
    if (k > n) {
      cout << 0;
      return;
    }
  }
  sort(a.begin(), a.end());
  long long cnt = 0, res = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && cnt < k) {
      cnt++;
      int pp = j;
      while (pp < n && a[pp] == a[j]) pp++;
      j = pp;
    }
    long long rr = j - i;
    res = max(res, rr);
    int k = i;
    while (k < n && a[k] == a[i]) k++;
    cnt--;
    i = k - 1;
  }
  cout << n - res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
