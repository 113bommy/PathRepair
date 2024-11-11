#include <bits/stdc++.h>
using namespace std;
bool forbid[200017];
vector<int> d[200017];
unsigned int dp[200017], par[200017];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long egcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long r = egcd(b, a % b, x, y);
  long long t = y;
  y = x - (a / b) * y;
  x = t;
  return r;
}
bool modular_linear_equation(long long a, long long b, long long n) {
  long long x, y, x0, i;
  long long d = egcd(a, n, x, y);
  if (b % d) return false;
  x0 = x * (b / d) % n;
  for (i = 1; i; i++) {
    if (x0 >= 0) break;
    x0 = (x0 + i * (n / d)) % n;
  }
  printf("%d ", x0);
  return true;
}
int main(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    forbid[tmp] = true;
  }
  for (int i = 1; i < m; i++) {
    if (!forbid[i]) d[gcd(i, m)].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    dp[i] >= d[i].size() ? 0 : dp[i] = d[i].size();
    for (int j = 2 * i; j <= m; j += i)
      if (dp[j] < dp[i] + d[j].size()) {
        dp[j] = dp[i] + d[j].size();
        par[j] = i;
      }
  }
  unsigned int deep = 0, id;
  for (int i = 0; i < m; i++) deep < dp[i] ? deep = dp[i], id = i : 0;
  vector<int> traceback;
  while (id != 0) {
    traceback.push_back(id);
    id = par[id];
  }
  reverse(traceback.begin(), traceback.end());
  int ans[200017], ans_i = 0;
  for (vector<int>::iterator i = traceback.begin(); i != traceback.end(); i++)
    for (vector<int>::iterator j = d[*i].begin(); j != d[*i].end(); j++) {
      ans[ans_i++] = *j;
    }
  forbid[0] ? 0 : (ans_i += 1, ans[ans_i - 1] = 0);
  printf("%d\n", ans_i);
  if (!ans_i) return 0;
  printf("%d ", ans[0]);
  for (int i = 1; i < ans_i; i++)
    modular_linear_equation(ans[i - 1], ans[i], m);
  return 0;
}
