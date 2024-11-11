#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MAX_N = 100001;
const long long MOD = 1000000007;
const long long INF = 1e18;
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n, p;
  cin >> n >> p;
  long long i = 0;
  while (true) {
    i++;
    if (n < i * p) {
      cout << -1 << endl;
      return 0;
    }
    long long num = n - i * p, cnt = 0;
    while (num) cnt += num % 2, num /= 2;
    if (cnt <= i) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
