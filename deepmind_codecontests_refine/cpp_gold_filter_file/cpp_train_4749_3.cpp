#include <bits/stdc++.h>
using namespace std;
inline int D() {
  int t;
  scanf("%d", &t);
  return t;
}
inline long long LLD() {
  long long t;
  scanf("%lld", &t);
  return t;
}
bool isPrime(long long n) {
  for (long long i = 2; i <= n / i; ++i)
    if (n % i == 0) return 0;
  return n > 1;
}
vector<long long> getDivisors(long long n) {
  vector<long long> ret;
  for (int i = 1; i <= n / i; ++i) {
    if (n % i == 0) {
      ret.push_back(i);
      if (n / i != i) ret.push_back(n / i);
    }
  }
  return ret;
}
long long GCD(long long a, long long b) { return b ? GCD(b, a % b) : a; }
long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
vector<long long> ret;
vector<long long> getFactors(long long n) {
  for (long long i = 2; i <= n / i; ++i)
    while (n % i == 0) {
      ret.push_back(i);
      n /= i;
    }
  if (n != 1) {
    ret.push_back(n);
  }
  return ret;
}
const int N = 1e6 + 5;
int vst[N], cnt[N];
vector<int> primes;
void seive() {
  for (int i = 2; i < N; ++i) {
    if (vst[i]) continue;
    primes.push_back(i);
    for (long long j = 1LL * i * i; j < N; j += i) vst[j] = 1;
  }
}
int cnt1[N];
void modSeive() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) ++cnt1[j];
  }
}
int cnt2[N];
void mod2Sieve() {
  for (int i = 2; i < N; ++i) {
    if (vst[i]) continue;
    for (long long j = i; j < N; j += i) {
      vst[j] = 1;
      int cntP = 0;
      int curr = j;
      while (curr % i == 0) {
        ++cntP;
        curr /= i;
      }
      cnt2[j] += cntP;
    }
  }
}
int main() {
  int n = D();
  int a[n];
  for (int i = 0; i < n; i++) {
    a[i] = D();
  }
  long long cn = 0, x = 0;
  bool flag = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      x++;
      flag = 1;
    } else if (flag) {
      for (int j = 1; j <= x; j++) {
        cn += j;
      }
      x = 0;
      flag = 0;
    }
  }
  if (x >= 1) {
    for (int j = 1; j <= x; j++) {
      cn += j;
    }
  }
  cout << n + cn;
}
