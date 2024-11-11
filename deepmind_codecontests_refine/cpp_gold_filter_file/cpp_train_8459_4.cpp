#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
bool p[maxn];
long long cnt[maxn];
vector<long long> prime_large, prime_small;
long long A(long long x) {
  cout << "A " << x << endl;
  long long y;
  cin >> y;
  return y;
}
long long B(long long x) {
  cout << "B " << x << endl;
  long long y;
  cin >> y;
  return y;
}
void C(long long x) { cout << "C " << x << endl; }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 2; i <= n; i++) {
    if (p[i] == 0) {
      if (i * i <= n)
        prime_small.push_back(i);
      else
        prime_large.push_back(i);
      for (long long j = i; j <= n; j += i) p[j] = 1;
    }
  }
  long long ans = 1;
  long long tmp = n;
  if (((long long)(prime_large).size()) >= 1) {
    long long block = sqrt(((long long)(prime_large).size()));
    for (long long j = 0; j * block < ((long long)(prime_large).size()); j++) {
      for (long long k = 0;
           k < block && j * block + k < ((long long)(prime_large).size());
           k++) {
        long long now = prime_large[j * block + k];
        B(now);
        tmp -= n / now;
      }
      if (A(1) != tmp) {
        for (long long k = 0;
             k < block && j * block + k < ((long long)(prime_large).size());
             k++) {
          long long now = prime_large[j * block + k];
          if (A(now) == 1) {
            ans *= now;
            break;
          }
        }
        break;
      }
    }
  }
  for (long long i : prime_small) {
    vector<long long> v;
    tmp = i;
    while (tmp <= n) {
      v.push_back(tmp);
      tmp *= i;
    }
    reverse((v).begin(), (v).end());
    for (long long j : v) {
      B(j);
      if (A(j) == 1) {
        ans *= j;
        break;
      }
    }
  }
  C(ans);
}
