#include <bits/stdc++.h>
using namespace std;
long long n, k;
int a, b;
vector<long long> v;
long long gcd(long long x, long long y) {
  if (x < y) swap(x, y);
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> a >> b;
  for (int i = 0; i < n; i++) {
    for (int j = -1; j <= 1; j += 2) {
      for (int j2 = -1; j2 <= 1; j2 += 2) {
        long long tren = i;
        tren *= k;
        tren += (a * j + b * j2) % k;
        while (tren < 0) tren += k;
        v.push_back(n * k / gcd(n * k, tren));
      }
    }
  }
  sort(v.begin(), v.end());
  cout << v[0] << " " << v[(int)v.size() - 1];
  return 0;
}
