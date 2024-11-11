#include <bits/stdc++.h>
using namespace std;
long long val(long long n) {
  return (n * (n - 1) * (n - 2) * (n - 3) * (n - 2)) / 120;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long n;
  cin >> n;
  vector<long long> cnt(51, 0);
  for (long long i = 50; i >= 5; i--) {
    long long x = val(i);
    while (n >= x) n -= x, cnt[i]++;
  }
  string a, b = "aaaaab";
  for (long long i = 1; i <= 50; i++) {
    a += 'a';
    while (cnt[i]--) a += 'b';
  }
  cout << a << " " << b << "\n";
}
