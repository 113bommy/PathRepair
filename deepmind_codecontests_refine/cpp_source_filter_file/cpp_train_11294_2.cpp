#include <bits/stdc++.h>
using namespace std;
void sc(int& a) { scanf("%d", &a); }
void sc(long long int& a) { scanf("%lld", &a); }
void sc(int& a, int& b) {
  sc(a);
  sc(b);
}
void sc(int& a, int& b, int& c) {
  sc(a);
  sc(b);
  sc(c);
}
void sc(long long int& a, long long int& b) {
  sc(a);
  sc(b);
}
void sc(long long int& a, long long int& b, long long int& c) {
  sc(a, b);
  sc(c);
}
void write(int a) { printf("%d", a); }
void write(long long int a) { printf("%lld", a); }
long long int modpow(long long int a, long long int b, long long int MOD) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b = b / 2;
  }
  return res % MOD;
}
pair<int, int> p[200005];
int main() {
  int n, i;
  sc(n);
  for (i = 0; i < n; i++) {
    sc(p[i].first);
    p[i].first += i;
    p[i].second = i;
  }
  sort(p, p + n);
  for (i = n - 1; i >= 0; i--) {
    p[i].first -= i;
  }
  for (i = 1; i <= n - 1; i++) {
    if (p[i].first < p[i - 1].first or p[0].first < 0 or p[i].first < 0) {
      cout << ":(";
      return 0;
    }
  }
  for (i = 0; i < n; i++) printf("%I64d ", p[i].first);
}
