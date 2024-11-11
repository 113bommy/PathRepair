#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
long long power(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long t = power(a, b / 2, m);
  t = (t * t) % m;
  if (b & 1) t = (t * a) % m;
  return t;
}
using namespace std;
int main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, b;
  cin >> n >> b;
  long long n1 = b;
  map<long long, long long> mt;
  while (n1 % 2 == 0) {
    n1 = n1 / 2;
    mt[2]++;
  }
  for (long long i = 3; i <= sqrt(n1); i++) {
    while (n1 % i == 0) {
      mt[i]++;
      n1 = n1 / i;
    }
  }
  if (n1 > 1) mt[n1]++;
  long long ans = 100000000000000;
  map<long long, long long>::iterator itr;
  for (itr = mt.begin(); itr != mt.end(); itr++) {
    long long anss = 0, nt = n;
    while (nt / itr->first >= 1) {
      anss += nt / itr->first;
      nt = nt / itr->first;
    }
    anss = anss / itr->second;
    if (anss < ans) ans = anss;
  }
  cout << ans << endl;
}
