#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
long long A[100005 * 10];
long long B[100005 * 10];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long tst = 1;
  for (long long tt = 1; tt <= tst; tt++) {
    long long n, mn = 1e12, a = 1, b = 1;
    cin >> n;
    long long val = n / 2;
    for (long long i = 1; i <= val; i++) {
      if (n % i == 0) {
        long long cnt = n / i;
        if (abs(cnt - i) < mn) a = i, b = cnt, mn = abs(i - cnt);
      }
    }
    if (a > b) swap(a, b);
    cout << a << " " << b << endl;
  }
  return 0;
}
