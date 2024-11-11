#include <bits/stdc++.h>
using namespace std;
long long gcd(long long ar1, long long ar2) {
  return ar2 == 0 ? ar1 : gcd(ar2, ar1 % ar2);
}
long long add(long long ar1, long long ar2, long long m) {
  if (ar1 >= m) ar1 %= m;
  if (ar2 >= m) ar2 %= m;
  if (ar1 < 0) ar1 += m;
  if (ar2 < 0) ar2 += m;
  long long res = ar1 + ar2;
  if (res >= m or res <= -m) res %= m;
  if (res < 0) res += m;
  return res;
}
long long mul(long long ar1, long long ar2, long long m) {
  if (ar1 >= m) ar1 %= m;
  if (ar2 >= m) ar2 %= m;
  if (ar1 < 0) ar1 += m;
  if (ar2 < 0) ar2 += m;
  long long res = ar1 * ar2;
  if (res >= m or res <= -m) res %= m;
  if (res < 0) res += m;
  return res;
}
long long pow_mod(long long ar1, long long ar2, long long m) {
  long long res = 1;
  ar1 = ar1 % m;
  while (ar2) {
    if (ar2 & 1) res = mul(res, ar1, m);
    ar2 >>= 1;
    ar1 = mul(ar1, ar1, m);
  }
  return res;
}
long long fastexp(long long ar1, long long ar2) {
  long long res = 1;
  while (ar2) {
    if (ar2 & 1) res = res * ar1;
    ar2 >>= 1;
    ar1 *= ar1;
  }
  return res;
}
long long gcdExtendido(long long ar1, long long ar2, long long *x,
                       long long *y) {
  if (ar1 == 0) {
    *x = 0;
    *y = 1;
    return ar2;
  }
  long long x1, y1;
  long long gcd = gcdExtendido(ar2 % ar1, ar1, &x1, &y1);
  *x = y1 - (ar2 / ar1) * x1;
  *y = x1;
  return gcd;
}
long long modInverso(long long ar1, long long m) {
  long long x, y;
  long long g = gcdExtendido(ar1, m, &x, &y);
  if (g != 1)
    return -1;
  else
    return (x % m + m) % m;
}
bool sortbysec(const pair<long long, long long> &ar1,
               const pair<long long, long long> &ar2) {
  return (ar1.second < ar2.second);
}
long long fact(long long n) {
  if (n <= 1) return 1;
  return mul(n, fact(n - 1), 1000000007);
}
bool probablyPrimeFermat(long long n, long long iter) {
  if (n < 4) return n == 2 || n == 3;
  for (long long i = 0; i < iter; i++) {
    long long a = 2 + abs(rand() % (n - 3));
    if (pow_mod(a, n - 1, n) != 1) return false;
  }
  return true;
}
bool checkPow2(long long n) { return (n > 0) && ((n & (n - 1)) == 0); }
signed main() {
  long long t = 3;
  vector<pair<long long, char> > cnt;
  cnt.push_back({0, 'A'});
  cnt.push_back({0, 'B'});
  cnt.push_back({0, 'C'});
  while (t--) {
    string s;
    cin >> s;
    if (s[1] == '>') {
      if (t == 0 && cnt[s[0] - 'A'].first < cnt[s[2] - 'A'].first) {
        cout << "Impossible\n";
        return 0;
      }
      cnt[s[0] - 'A'].first += cnt[s[2] - 'A'].first + 1;
    } else {
      if (t == 0 && cnt[s[2] - 'A'].first < cnt[s[0] - 'A'].first) {
        cout << "Impossible\n";
        return 0;
      }
      cnt[s[2] - 'A'].first += cnt[s[0] - 'A'].first + 1;
    }
  }
  sort(cnt.begin(), cnt.end());
  if (cnt[0].first == cnt[1].first || cnt[1].first == cnt[2].first) {
    cout << "Impossible\n";
  } else {
    for (long long i = 0; i < 3; i++) cout << cnt[i].second;
  }
  cout << '\n';
  return 0;
}
