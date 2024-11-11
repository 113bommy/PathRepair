#include <bits/stdc++.h>
using namespace std;
long long n;
int digits(long long t) {
  int res = 0;
  while (t > 0) {
    res++;
    t /= 10;
  }
  return res;
}
long long f(long long m, long long d) {
  if (m % 2 == 0) return f(m - 1, d);
  if (digits(m) + digits((1ll << d)) > 19) return (1ll << 60ll);
  return m * ((1ll << d) - 1) + m * (m - 1) / 2;
}
long long bin(long long d) {
  long long ini = 1;
  long long fin = 1000000001;
  long long mid;
  while (fin - ini > 1) {
    mid = (ini + fin) / 2;
    if (f(mid, d) < n) {
      ini = mid;
    } else {
      fin = mid;
    }
  }
  if (f(ini, d) == n) return (1ll << d) * ini;
  if (f(fin, d) == n) return (1ll << d) * fin;
  return -1;
}
int main() {
  cin >> n;
  set<long long> res;
  for (int i = 0; i < 60; i++) {
    long long t = bin(i);
    if (t != -1) {
      res.insert(t);
    }
  }
  if (res.size() == 0) {
    cout << -1 << endl;
  } else {
    for (set<long long>::iterator it = res.begin(); it != res.end(); it++) {
      cout << (*it) << endl;
    }
  }
  return 0;
}
