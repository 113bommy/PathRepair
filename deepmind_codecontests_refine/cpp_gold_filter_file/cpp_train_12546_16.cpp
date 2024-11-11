#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
long long powm(long long a, long long p, long long m) {
  long long r = 1 % m;
  while (p) {
    if (p & 1) r = r * a % m;
    p >>= 1;
    a = a * a % m;
  }
  return r;
}
int main() {
  int n, m = inf;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    sum += a;
    if (a % 2 == 1) m = min(m, a);
  }
  if (sum % 2 == 1) sum -= m;
  cout << sum << endl;
  return 0;
}
