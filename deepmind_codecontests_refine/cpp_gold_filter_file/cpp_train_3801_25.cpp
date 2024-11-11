#include <bits/stdc++.h>
using namespace std;
int a[6000005];
vector<long long> primes;
vector<pair<long long, long long> > v;
void sieve() {
  int i, j;
  a[0] = 1;
  a[1] = 1;
  primes.push_back(2);
  for (i = 4; i < 6000005; i += 2) a[i] = 1;
  for (i = 3; i * i < 6000005; i += 2) {
    if (a[i] == 0) {
      primes.push_back(i);
      for (j = i + i; j < 6000005; j += i) a[j] = 1;
    }
  }
  for (; i < 6000005; i++)
    if (a[i] == 0) primes.push_back(i);
}
int main() {
  long long x, y, t1, m, n, i, j, t2;
  scanf("%lld", &x);
  sieve();
  t1 = x;
  for (i = 0; i < primes.size(); i++) {
    while (t1 % primes[i] == 0) {
      t1 /= primes[i];
    }
  }
  y = x / t1;
  y *= 6;
  for (i = 1; i < 6000005; i++) {
    if ((y % (i * (i + 1)) == 0)) {
      t1 = ((x * 6) / (i * (i + 1))) + (i - 1);
      if (t1 % 3 != 0) continue;
      t1 /= 3;
      if (i > t1) continue;
      v.push_back(make_pair(i, t1));
      if (i != t1) v.push_back(make_pair(t1, i));
    }
  }
  sort(v.begin(), v.end());
  printf("%d\n", (int)v.size());
  for (i = 0; i < v.size(); i++) printf("%lld %lld\n", v[i].first, v[i].second);
  return 0;
}
