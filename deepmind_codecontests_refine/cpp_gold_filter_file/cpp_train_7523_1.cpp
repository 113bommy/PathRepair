#include <bits/stdc++.h>
using namespace std;
long long fact(int n, int l) {
  if (n == 0 || n == 1) return 1;
  long long f = n;
  for (long long i = n - 1; i >= (l == 0 ? 1 : l); i--) {
    f *= i;
  }
  return f;
}
void solve() {
  long long n;
  scanf("%lld", &n);
  map<long long, long long> mp;
  long long i, j, k;
  long long sum, cnt = 0;
  scanf("%lld", &sum);
  mp[sum]++;
  for (i = 1; i < n; i++) {
    scanf("%lld", &j);
    sum += j;
    if (sum == 0) {
      sum = j;
      cnt++;
      mp.clear();
      mp[j] = 1;
    } else {
      if (mp.find(sum) != mp.end()) {
        cnt += mp[sum];
        sum = j;
        mp.clear();
        mp[j] = 1;
      } else {
        mp[sum]++;
      }
    }
  }
  printf("%lld", cnt);
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
    cout << endl;
  }
}
