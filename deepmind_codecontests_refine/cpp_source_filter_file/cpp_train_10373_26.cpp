#include <bits/stdc++.h>
using namespace std;
const long long int K = 1e9 + 7;
long long int gt[10005], rev[10005];
long long int mu(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int q = mu(a, n / 2);
  if (n % 2 == 0) return q * q % K;
  return q * q % K * a % K;
}
long long int Combi(long long int n, long long int k) {
  if (k > n) return 0;
  return gt[n] * rev[n - k] % K * rev[k] % K;
}
long long int C[1005];
string s1[1005];
map<string, long long int> ma;
set<string> S;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  gt[0] = rev[0] = 1;
  for (int i = 1; i <= 1004; i++) {
    gt[i] = gt[i - 1] * i;
    rev[i] = mu(gt[i], K - 2);
  }
  C[0] = 1;
  for (int n = 1; n <= 1000; n++) {
    for (int k = 0; k <= n - 1; k++) {
      C[n] = (C[n] + Combi(n - 1, k) * C[k] % K) % K;
    }
  }
  long long int m, n;
  cin >> m >> n;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int i = 0; i <= m - 1; i++) {
      s1[i] += s[i];
    }
  }
  for (int i = 0; i <= m - 1; i++) {
    S.insert(s1[i]);
    ma[s1[i]]++;
  }
  long long int res = 1;
  for (auto i : S) {
    res = (res * C[ma[i]]) % K;
  }
  cout << res << endl;
  return 0;
}
