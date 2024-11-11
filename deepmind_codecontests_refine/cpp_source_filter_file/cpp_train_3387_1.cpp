#include <bits/stdc++.h>
using namespace std;
const long long M = 1e7 + 10;
long long prime[M];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
vector<int> graph[200001];
void precompute() {
  for (long long i = 2; i < M; i++) {
    if (!prime[i]) {
      for (long long j = 1; i * j < M; j++) prime[i * j] = i;
    }
  }
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, j, n, m, k, temp, x, y, z;
  cin >> n >> k;
  vector<long long> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  long long l = 0, r = 0, change = 0, curr = 0, res = INT_MIN, lm, rm;
  while (r < n) {
    if (a[r] == 0) change++;
    r++;
    while (change > k) {
      if (a[l] == 0) change--;
      l++;
    }
    if (res < r - l) {
      lm = l;
      rm = r;
      res = r - l;
    }
  }
  cout << res << "\n";
  for (i = 0; i < l; i++) cout << a[i] << " ";
  for (i = l; i < r; i++) cout << 1 << " ";
  for (i = r; i < n; i++) cout << a[i] << " ";
  cout << "\n";
  return 0;
}
