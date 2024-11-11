#include <bits/stdc++.h>
using namespace std;
long long n, m, k, p, ans, l, r, i, j, k1, k0, a[100001];
map<long long, long long> t;
string s;
int main() {
  cin >> n >> p >> k;
  for (int i = 0; i < n; i++) {
    long long v;
    cin >> v;
    long long o = ((v * v % p * v % p * v % p - k * v) % p + p) % p;
    ans += t[o];
    t[o]++;
    ;
  }
  cout << ans;
  return 0;
}
