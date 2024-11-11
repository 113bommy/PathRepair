#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000000 + 9];
void sieve(int N) {
  isPrime[0] = true;
  isPrime[1] = true;
  for (int i = 2; i * i <= N; ++i) {
    if (isPrime[i] == false) {
      for (int j = i * i; j <= N; j += i) isPrime[j] = true;
    }
  }
}
long long int ans = 1e10;
long long int fac(long long int x) {
  long long int tmp = x;
  long long int t = 1;
  for (long long int i = 2; i * i <= tmp; ++i) {
    if (tmp % i == 0) {
      while (tmp % i == 0) {
        tmp /= i;
      }
      if (i > t) t = i;
      if (x - i >= 3) ans = min(ans, x - i + 1);
    }
  }
  if (tmp != 1) {
    if (tmp > t) t = tmp;
    if (x - tmp >= 3) ans = min(ans, x - tmp + 1);
  }
  if (x >= 3) ans = min(ans, x);
  return t;
}
void machayenge() {
  long long int x;
  cin >> x;
  long long int tmp = fac(x);
  long long int rs = x - tmp;
  long long int es = x;
  for (long long int i = rs; i <= es; ++i) {
    if (i % tmp != 0) {
      long long int tt = fac(i);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  machayenge();
  return 0;
}
