#include <bits/stdc++.h>
using namespace std;
long long T, k, p, sum;
long long generator(long long n) {
  long long res = n;
  long long t = n;
  while (t--) {
    res = res * 10 + res % 10;
    t /= 10;
  }
  return res;
}
void solution() {
  cin >> k >> p;
  sum = 0;
  for (long long i = 1; i < k + 1; ++i) {
    sum = (sum + generator(i)) % p;
  }
  cout << sum % p << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  while (T--) solution();
}
