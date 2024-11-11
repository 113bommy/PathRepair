#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string toBin(long long a) {
  string res = "";
  while (a) {
    res += char((a & 1) + '0');
    a >>= 1;
  }
  reverse(res.begin(), res.end());
  return res;
}
const int mod = 1e9 + 7;
long long expo(long long base, long long pow) {
  long long ans = 1;
  while (pow != 0) {
    if (pow & 1 == 1) {
      ans = ans * base;
      ans = ans % mod;
    }
    base *= base;
    base %= mod;
    pow /= 2;
  }
  return ans;
}
long long inv(long long x) { return expo(x, mod - 2); }
bool isPal(string ss) {
  int len = ss.length();
  for (int i = 0; i < len / 2; i++) {
    int comp = len - i - 1;
    if (ss[i] != ss[comp]) return false;
  }
  return true;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
const int M = 200101;
int n, k;
int sub[M];
vector<int> vec[M];
int ans = 0;
int dfs(int u, int p) {
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (v == p) continue;
    sub[u] += dfs(v, u);
  }
  ans += min(sub[u], 2 * k - sub[u]);
  return sub[u];
}
int main() {
  scanf("%d", &(n));
  scanf("%d", &(k));
  for (int i = 1; i <= 2 * k; i++) {
    int el;
    scanf("%d", &(el));
    sub[el] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d", &(a));
    scanf("%d", &(b));
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  dfs(1, 0);
  cout << ans;
}
