#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 1;
const int alp = 257;
long long binpow(long long a, long long n, long long mod) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 1) {
    return (binpow(a, n - 1, mod) * a) % mod;
  } else {
    long long b = binpow(a, n / 2, mod);
    return (b * b) % mod;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long phi(int n) {
  long long result = n;
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  if (n > 1) {
    result -= result / n;
  }
  return result;
}
vector<long long> ans1;
vector<char> ans2;
vector<long long> ans3;
int main() {
  long long n, k;
  int t = 1;
  while (t--) {
    cin >> n;
    long long pov = 0;
    int pos1 = 0;
    int fl = 0;
    while (n >= (1ll << pov)) {
      if (gcd(((n << pov) ^ n), n) == 1 && fl == 0) {
        pos1 = pov;
        fl = 1;
      }
      pov++;
    }
    long long y = phi(n);
    long long pov1 = 0;
    while ((pov) > pov1) {
      long long nn = (n << pov1);
      ans1.push_back(nn);
      ans3.push_back(nn);
      ans2.push_back('+');
      pov1++;
    }
    ans1.push_back(n);
    ans3.push_back((1ll << pos1) * n);
    ans2.push_back('^');
    long long x = n ^ ((1ll << pos1) * n);
    long long xx = binpow(x % n, y - 1, n);
    long long now = x;
    pov1 = 0;
    while ((xx - 1) >= (1ll << pov1)) {
      if ((((xx - 1) >> (pov1)) & 1) == 1) {
        ans1.push_back(now);
        ans3.push_back((x << pov1));
        ans2.push_back('+');
        now += (x << pov1);
      }
      ans1.push_back((x << pov1));
      ans3.push_back((x << pov1));
      ans2.push_back('+');
      pov1++;
    }
    long long z = (now - 1) / n;
    long long yy = z;
    pov1 = 0;
    long long noww = n;
    while ((yy - 1) >= (1ll << pov1)) {
      if ((((yy - 1) >> pov1) & 1) == 1) {
        ans1.push_back(noww);
        ans3.push_back((n << pov1));
        ans2.push_back('+');
        noww += (n << pov1);
      }
      ans1.push_back((n << pov1));
      ans3.push_back((n << pov1));
      ans2.push_back('+');
      pov1++;
    }
    ans1.push_back(now);
    ans3.push_back(noww);
    ans2.push_back('+');
    ans1.push_back(noww);
    ans3.push_back(noww);
    ans2.push_back('+');
    ans1.push_back(noww + now);
    ans3.push_back(noww + noww);
    ans2.push_back('^');
    cout << ans1.size() << "\n";
    for (int q = 0; q < ans1.size(); q++) {
      cout << ans1[q] << " " << ans2[q] << " " << ans3[q] << "\n";
    }
  }
}
