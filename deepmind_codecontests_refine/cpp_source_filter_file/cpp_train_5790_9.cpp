#include <bits/stdc++.h>
using namespace std;
const int MAX = 2555;
bool is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
vector<int> primes;
int f[MAX][MAX];
int ps[MAX][MAX];
char buf[MAX];
int ones(int i1, int j1, int i2, int j2) {
  return ps[i2][j2] - ps[i1 - 1][j2] - ps[i2][j1 - 1] + ps[i1 - 1][j1 - 1];
}
int solve(int k, int n, int m) {
  n += k - n % k;
  m += k - m % k;
  int ans = 0;
  for (int i = k; i <= n; i += k) {
    for (int j = k; j <= m; j += k) {
      int _ones = ones(i - k + 1, j - k + 1, i, j);
      ans += min(_ones, k * k - _ones);
    }
  }
  return ans;
}
int main() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      f[i][j] = 0;
      ps[i][j] = 0;
    }
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", buf);
    for (int j = 0; j < m; j++) {
      f[i][j + 1] = buf[j] - '0';
    }
  }
  for (int i = 1; i < MAX; i++) {
    for (int j = 1; j < MAX; j++) {
      ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + f[i][j];
    }
  }
  for (int i = 2; i <= 2500; i++) {
    if (is_prime(i)) primes.push_back(i);
  }
  int best = INT_MAX;
  for (int prime : primes) {
    int cur = solve(prime, n, m);
    best = min(best, cur);
  }
  printf("%d", best);
  return 0;
}
