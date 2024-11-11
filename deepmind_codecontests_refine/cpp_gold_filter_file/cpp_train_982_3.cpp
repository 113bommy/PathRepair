#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long a, long long b, long long m) {
  if (b == 0) return 1 % m;
  long long x = bigmod(a, b / 2, m);
  x = (x % m * x % m) % m;
  if (b % 2) x = (x % m * a % m) % m;
  return x;
}
int main() {
  long long n, k, d, p, an = 0;
  cin >> n >> k >> d;
  p = k;
  for (int i = 0; i < d; i++) {
    if (n <= p) {
      an = 1;
      break;
    }
    p *= k;
  }
  if (!an) return 0 & puts("-1");
  vector<vector<int> > a;
  for (int i = 0; i < n; i++) {
    int m = i;
    vector<int> s;
    while (m && s.size() < d) {
      s.push_back(m % k);
      m /= k;
    }
    while (s.size() < d) s.push_back(0);
    a.push_back(s);
  }
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < n; j++) cout << a[j][i] + 1 << " ";
    puts("");
  }
}
