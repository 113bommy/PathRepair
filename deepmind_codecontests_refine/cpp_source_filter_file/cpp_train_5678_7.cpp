#include <bits/stdc++.h>
using namespace std;
long long power(long long, long long);
long long mpower(long long, long long);
vector<long long> v;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i <= 100000; i++) {
    long long cnt = 0;
    long long t = 5;
    while (i >= t) {
      cnt += i / t;
      t = t * 5;
    }
    v.push_back(cnt);
  }
  long long n;
  cin >> n;
  vector<long long> ans;
  for (long long i = 1; i <= 100000; i++) {
    if (v[i - 1] == n) ans.push_back(i);
    if (v[i - 1] > n) break;
  }
  cout << ans.size() << endl;
  for (long long i : ans) cout << i << " ";
  return 0;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = res * a;
    a = a * a;
    b = b / 2;
  }
  return res;
}
long long mpower(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return res;
}
