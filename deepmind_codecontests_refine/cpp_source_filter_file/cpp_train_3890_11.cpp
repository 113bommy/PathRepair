#include <bits/stdc++.h>
using namespace std;
int n, m;
long long powr(long long u, long long e) {
  if (e < 0) return 0;
  if (!e) return 1;
  if (e == 1) return u;
  long long temp = powr(u, e / 2);
  temp = (temp * temp) % m;
  if (e % 2) temp = (temp * u) % m;
  return temp;
}
long long sumPows(long long a, long long e) {
  if (e <= 0) return 0;
  if (e == 1) return a;
  if (e % 2) return ((a * sumPows(a, e - 1)) % m + a) % m;
  return (sumPows(a, e / 2) * (1 + powr(a, e / 2))) % m;
}
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1) {
    cout << 2;
    return 0;
  }
  cout << ((powr(3, n - 1) * 2) % m + (2 * sumPows(3, n - 2)) % m + 2) % m;
}
