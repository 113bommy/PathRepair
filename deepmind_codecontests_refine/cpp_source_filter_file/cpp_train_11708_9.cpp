#include <bits/stdc++.h>
#pragma 03
using namespace std;
long long n, m;
long long a[40];
long long t[40];
long long ans = 0;
void f(long long ind, long long num, long long k) {
  if (ind == n) {
    long long inc = 1;
    for (long long i = 0; i < m; i++) {
      if ((n - __builtin_popcountll(num ^ a[i])) != t[i]) inc = 0;
    }
    ans += inc;
    return;
  }
  f(ind + 1, num ^ (1LL << ind), k);
  if (k) f(ind + 1, num, k - 1);
}
int main() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    string s;
    cin >> s;
    cin >> t[i];
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') a[i] |= (1LL << j);
    }
  }
  f(0LL, a[1], t[1]);
  cout << ans << endl;
  return 0;
}
