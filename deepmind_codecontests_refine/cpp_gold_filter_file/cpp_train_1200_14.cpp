#include <bits/stdc++.h>
using namespace std;
const int MAX = 320010;
long long phi[10005][105], p2[MAX], ans[MAX];
int len, vis[MAX];
void init() {
  len = 0;
  for (int i = 2; i < MAX; i++) {
    if (!vis[i]) {
      for (int j = i + i; j < MAX; j += i) {
        vis[j] = 1;
      }
      p2[len++] = i;
      ans[i] = ans[i - 1] + 1;
      continue;
    }
    ans[i] = ans[i - 1];
  }
  for (int i = 0; i <= 10000; i++) {
    phi[i][0] = (long long)i;
    for (int j = 1; j <= 100; j++) {
      phi[i][j] = phi[i][j - 1] - phi[i / p2[j - 1]][j - 1];
    }
  }
}
long long solve_phi(long long m, long long n) {
  if (!n) {
    return m;
  }
  if (p2[n - 1] >= m) {
    return 1;
  }
  if (m <= 10000 && n <= 100) {
    return phi[m][n];
  }
  return solve_phi(m, n - 1) - solve_phi(m / p2[n - 1], n - 1);
}
long long solve_p2(long long m) {
  if (m < (long long)MAX) {
    return ans[m];
  }
  long long y = (int)cbrt(m * 1.0);
  long long n = ans[y];
  long long sum = solve_phi(m, n) + n - 1;
  for (long long i = n; p2[i] * p2[i] <= m; i++) {
    sum = sum - solve_p2(m / p2[i]) + solve_p2(p2[i]) - 1;
  }
  return sum;
}
int main() {
  init();
  long long n;
  cin >> n;
  long long S = cbrt(n * 1.0);
  S = solve_p2(S);
  long long temp = 0;
  for (int i = 0; i < len; i++) {
    if (p2[i] * p2[i] >= n) {
      break;
    }
    long long x = n / p2[i];
    long long s = solve_p2(x);
    s -= temp + 1;
    temp = solve_p2(p2[i]);
    S += s;
  }
  cout << S << '\n';
  return 0;
}
