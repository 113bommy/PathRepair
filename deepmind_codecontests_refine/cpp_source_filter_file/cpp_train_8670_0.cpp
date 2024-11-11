#include <bits/stdc++.h>
using namespace std;
const int p = 1000000000 + 7;
int n, k, m;
map<int, int> cnt;
int inv(int x) {
  int ret = 1;
  int a = x;
  int n = p - 2;
  while (n) {
    if (n & 1) {
      ret = ret * (long long)a % p;
    }
    a = a * (long long)a % p;
    n >>= 1;
  }
  return ret;
}
int lucky(int t) {
  while (t) {
    if (t % 10 != 4 && t % 10 != 7) {
      return 0;
    }
    t /= 10;
  }
  return 1;
}
int f[1000];
int fact[110000], invFact[110000];
int c(int m, int k) {
  return fact[m] * (long long)invFact[k] % p * (long long)invFact[m - k] % p;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    cin >> tmp;
    if (lucky(tmp)) {
      cnt[tmp]++;
    } else {
      m++;
    }
  }
  fact[0] = 1;
  for (int i = 1; i < 110000; i++) {
    fact[i] = fact[i - 1] * (long long)i % p;
  }
  invFact[0] = 1;
  for (int i = 1; i < 110000; i++) {
    invFact[i] = invFact[i - 1] * (long long)inv(i) % p;
  }
  f[0] = 1;
  for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
    int x = it->first;
    int c = it->second;
    for (int i = 999; i > 0; --i) {
      f[i] = (f[i - 1] * (long long)c + f[i]) % p;
    }
  }
  long long ans = 0;
  for (int i = 0; i < 1000; i++) {
    if (f[i] > 0) {
      int rest = k - i;
      if (rest >= 0 && rest <= m) {
        ans += c(m, rest) * (long long)f[i] % p;
        ans %= p;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
