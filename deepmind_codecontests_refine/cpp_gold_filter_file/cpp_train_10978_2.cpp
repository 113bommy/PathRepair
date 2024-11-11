#include <bits/stdc++.h>
using namespace std;
long long a, b, sumi, sumj;
void add(long long &a, long long b) { a = (a + b) % 1000000007; }
long long mul(long long a, long long b) { return (a * b) % 1000000007; }
int main() {
  ios_base::sync_with_stdio(false);
  cin >> a >> b;
  long long ans = 0;
  for (long long j = 1; j <= b - 1; ++j) add(sumj, j);
  for (long long i = 1; i <= a; ++i) add(sumi, mul(i, sumj));
  ans = (mul(a, sumj) + mul(b, sumi)) % 1000000007;
  cout << ans << endl;
  return 0;
}
