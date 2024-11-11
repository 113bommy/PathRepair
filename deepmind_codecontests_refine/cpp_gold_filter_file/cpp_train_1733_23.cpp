#include <bits/stdc++.h>
using namespace std;
int isprime[1000006];
vector<vector<int> > facts(1000006, vector<int>());
void sieve() {
  isprime[0] = 1;
  isprime[1] = 1;
  for (long long i = 2; i * i < 1000006; i++) {
    if (isprime[i]) continue;
    for (long long j = i * i; j < 1000006; j += i) isprime[j] = 1;
  }
  for (int i = 2; i < 1000006; i++) {
    if (isprime[i]) continue;
    for (int j = i; j < 1000006; j += i) facts[j].push_back(i);
  }
}
long long f(long long x, long long p) {
  int sz = facts[p].size();
  long long ans = 0;
  for (int i = 0; i < (1 << sz); i++) {
    int c = 0;
    long long num = 1;
    for (int j = 0; j < sz; j++) {
      if ((i >> j) & 1) {
        num *= facts[p][j];
        c++;
      }
    }
    if (c % 2)
      ans -= x / num;
    else
      ans += x / num;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  sieve();
  while (t--) {
    long long x, p, k;
    cin >> x >> p >> k;
    long long l = x;
    long long r = 100000000000000000;
    long long temp = f(x, p);
    while (l < r) {
      long long mid = (l + r) / 2;
      if (f(mid, p) - temp >= k)
        r = mid;
      else
        l = mid + 1;
    }
    cout << l << endl;
  }
}
