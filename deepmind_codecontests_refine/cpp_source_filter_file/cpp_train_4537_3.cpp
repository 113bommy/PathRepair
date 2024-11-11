#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string toBin(long long a) {
  string res = "";
  while (a) {
    res += char((a & 1) + '0');
    a >>= 1;
  }
  reverse(res.begin(), res.end());
  return res;
}
const int mod = 1e9 + 7;
long long expo(long long base, long long pow) {
  long long ans = 1;
  while (pow != 0) {
    if (pow & 1 == 1) {
      ans = ans * base;
      ans = ans % mod;
    }
    base *= base;
    base %= mod;
    pow /= 2;
  }
  return ans;
}
long long inv(long long x) { return expo(x, mod - 2); }
bool isPal(string ss) {
  int len = ss.length();
  for (int i = 0; i < len / 2; i++) {
    int comp = len - i - 1;
    if (ss[i] != ss[comp]) return false;
  }
  return true;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
const int M = 1001111;
vector<int> BIT(M);
long long res = 1;
int isP[222];
int N, K, X = 0;
void sieve() {
  isP[1] = 1;
  for (int i = 2; i < 100; i++) {
    if (isP[i]) continue;
    for (long long j = i * 1LL * i; j < 100; j += i) {
      isP[j] = 1;
    }
  }
}
long long dofor(int a, int b) {
  long long ult = 0;
  for (int r = b + 1; r > 0; r -= r & -r) ult += BIT[r];
  for (int l = a; l > 0; l -= l & -l) ult -= BIT[l];
  if (a > b) {
    for (int r = N; r > 0; r -= r & -r) ult += BIT[r];
  }
  return ult;
}
void read() {
  cin >> N >> K;
  K = min(N, N - K);
}
void print(long long ans) { printf("%lld ", ans); }
void up(int we) {
  we = we + 1;
  for (; we < M; we += we & -we) BIT[we]++;
}
void solve() {
  for (int i = 0; i < N; i++) {
    int st = (X + 1) % N;
    int en = (X + K - 1) % N;
    res += dofor(st, en) + 1;
    print(res);
    up(X);
    up((X + K) % N);
    X = (X + K) % N;
  }
}
int main() {
  sieve();
  read();
  solve();
}
