#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15 + 7;
const long long N = 1e6;
long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long fpow(long long n, long long k, long long p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = MOD) { return fpow(a, p - 2, p); }
long long mult(long long a, long long b, long long p = MOD) {
  return (long long)((a % p) * (b % p)) % p;
}
vector<long long> prime(N + 1);
void sieve() {
  prime[0] = prime[1] = 1;
  for (long long i = 2; i <= N; i++) {
    if (!prime[i]) {
      prime[i] = i;
      for (long long j = i * i; j <= N; j += i)
        if (!prime[j]) prime[j] = i;
    }
  }
}
long long n, k;
bool query(long long l, long long r) {
  cout << l << " " << r << "\n";
  cout.flush();
  string second;
  cin >> second;
  if (second[0] == 'B')
    exit(0);
  else if (second[0] == 'Y')
    return true;
  else if (second[0] == 'N')
    return false;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  clock_t tStart = clock();
  cin >> n >> k;
  srand(10534046);
  long long left = 1ll, right = n;
  while (true) {
    long long templ = left, tempr = right;
    while ((tempr - templ) > (5 * k)) {
      long long tempmid = (tempr + templ) / 2;
      if (query(templ, tempmid))
        tempr = tempmid;
      else
        templ = tempmid;
      templ = max(1ll, templ - k);
      tempr = min(n, tempr + k);
    }
    long long t1 = tempr - templ + 1;
    long long t2 = templ + (long long)rand() % t1;
    if (query(t2, t2))
      return 0;
    else {
      left = max(1ll, templ - k);
      right = min(n, tempr + k);
    }
  }
  cerr << "Time Elapsed : " << fixed << setprecision(10)
       << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\n";
  return 0;
}
