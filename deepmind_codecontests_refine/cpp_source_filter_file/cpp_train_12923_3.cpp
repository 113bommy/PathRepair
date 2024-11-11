#include <bits/stdc++.h>
using namespace std;
long long n, i, j, k, l, m, b;
map<long long, long long> q;
long long fx(long long x) {
  long long nn = n, o = 0;
  while (nn / x) {
    o += nn / x;
    nn %= x;
  }
  return o;
}
int main() {
  cin >> n >> b;
  for (int i = 2; i * i <= b; i++) {
    if (b % i == 0) {
      while (b % i == 0) {
        q[i]++;
        b /= i;
      }
    }
  }
  if (b > 1) {
    q[b]++;
  }
  m = 1e18;
  for (map<long long, long long>::iterator it = q.begin(); it != q.end();
       it++) {
    k = it->first;
    m = min(m, fx(k) / it->second);
  }
  cout << m;
}
