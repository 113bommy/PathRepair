#include <bits/stdc++.h>
using namespace std;
long long binpow(long long base, long long exp, int mod) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return res;
}
long long mod(long long x) {
  return ((x % 1000000007LL + 1000000007LL) % 1000000007LL);
}
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n;
  cin >> n;
  vector<long long int> v, ans;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    v.push_back(x);
  };
  for (int i = 1; i < n; i++) {
    ans.push_back(abs(v[i] - v[i - 1]));
  }
  long long int final = (-1) * (1e9 + 1);
  long long int i = 0, j = 1;
  final = ans[i];
  long long int sum = ans[i];
  for (; j < ans.size(); j++) {
    ((j - i) % 2 == 0) ? (sum += ans[j]) : (sum -= ans[j]);
    if (sum > final) {
      final = sum;
    }
    if (sum < 0) {
      i = j + 1;
      sum = 0;
    }
  }
  if (n != 2) {
    i = 1, j = 2;
    long long int final2 = ans[i];
    sum = ans[i];
    for (; j < ans.size(); j++) {
      ((j - i) % 2 == 0) ? (sum += ans[j]) : (sum -= ans[j]);
      if (sum > final2) {
        final2 = sum;
      }
      if (sum < 0) {
        i = j + 1;
        sum = 0;
      }
    }
    final = max(final, final2);
  }
  cout << final << "\n";
}
