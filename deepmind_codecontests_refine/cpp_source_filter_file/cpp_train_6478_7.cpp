#include <bits/stdc++.h>
using namespace std;
long long exp(long long x, long long y, long long p) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % p) % p;
    x = (x * x) % p;
    y /= 2;
  }
  return res;
}
long long exp(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x);
    x = (x * x);
    y /= 2;
  }
  return res;
}
long long sv[100000];
void seive() {
  fill(sv, sv + 10000, 1);
  sv[0] = 0;
  sv[1] = 0;
  for (long long i = 2; i * i < 100000; i++) {
    if (sv[i]) {
      for (long long j = i * i; j < 100000; j += i) sv[j] = 0;
    }
  }
}
bool compare(pair<long long, long long> p, pair<long long, long long> q) {
  return p.first < q.first;
}
int main() {
  long long n;
  cin >> n;
  long long a[n], b[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  long long ca = 0, cb = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 1 && b[i] == 0) {
      ca++;
    } else if (a[i] == 0 && b[i] == 1) {
      cb++;
    }
  }
  if (ca > cb) {
    cout << 0 << endl;
  } else if (ca == 0) {
    cout << -1 << endl;
  } else
    cout << (long long)(cb / ca) + 1 << endl;
}
