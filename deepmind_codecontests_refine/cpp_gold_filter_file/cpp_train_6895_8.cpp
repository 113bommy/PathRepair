#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1000 * 1000 * 1000;
const int mod = 998244353;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
int c[105][105];
long long d;
int q;
vector<long long> pr;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int cnt(long long a, long long b) {
  if (a < b) swap(a, b);
  a /= b;
  int s = 0;
  vector<int> mas;
  for (int i = 0; i < (int)pr.size(); i++) {
    int c = 0;
    while (a % pr[i] == 0) {
      a /= pr[i];
      ++c;
    }
    if (c != 0) mas.push_back(c);
    s += c;
  }
  int answ = 1;
  for (int i = 0; i < (int)mas.size(); i++) {
    answ = answ * 1ll * c[s][mas[i]] % mod;
    s -= mas[i];
  }
  return answ;
}
int main() {
  c[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  cin >> d;
  scanf("%d", &q);
  if (d == 1) {
    while (q--) {
      long long u, v;
      scanf("%lld%lld", &u, &v);
      printf("1\n");
    }
    return 0;
  }
  for (long long i = 2; i * i <= d; i++) {
    if (d % i == 0) {
      pr.push_back(i);
      while (d % i == 0) {
        d /= i;
      }
    }
  }
  if (d != 1) {
    pr.push_back(d);
  }
  while (q--) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    long long p = gcd(u, v);
    printf("%d\n", (cnt(u, p) * 1ll * cnt(v, p)) % mod);
  }
  return 0;
}
