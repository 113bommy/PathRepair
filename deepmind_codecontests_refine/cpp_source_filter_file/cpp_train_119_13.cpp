#include <bits/stdc++.h>
long long mod = 1000000007;
long long mod2 = 998244353;
long long OO = 1e18;
using namespace std;
long long ans[500500];
long long cnt[500];
long long n, a[100100];
vector<long long> v;
void Get_digit(long long x) {
  while (x) {
    v.push_back(x % 10);
    x /= 10;
  }
}
int main() {
  long long i, j;
  ;
  long long k;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    Get_digit(a[i]);
    cnt[v.size()]++;
    v.clear();
  }
  for (i = 0; i < n; i++) {
    Get_digit(a[i]);
    for (k = 1; k <= 9; k++) {
      if (k >= v.size()) {
        for (j = 0; j < v.size(); j++) {
          ans[(j + 1) * 2 - 1] += v[j] * cnt[k];
          ans[(j + 1) * 2] += v[j] * cnt[k];
        }
      } else {
        for (j = 0; j < k; j++) {
          ans[(j + 1) * 2 - 1] += v[j] * cnt[k];
          ans[(j + 1) * 2] += v[j] * cnt[k];
        }
        long long indx = k * 2 + 1;
        for (j = k; j < v.size(); j++) {
          ans[indx] += v[j] * cnt[k] * 2;
          indx++;
        }
      }
    }
    v.clear();
  }
  long long load = 0;
  for (i = 1; i < 500400; i++) {
    ans[i] += load;
    load = ans[i] / 10;
    ans[i] %= 10;
  }
  long long x = 0;
  for (i = 500400; i > 0; i--) {
    x += ans[i];
    if (i != 1) x *= 10;
    x %= mod2;
  }
  cout << x;
  return 0;
}
