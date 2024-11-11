#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
vector<int> pi;
long long int power(long long int a, long long int b) {
  a %= MOD;
  long long int res = 1;
  while (b > 0) {
    if (b % 2) res = (res * a) % MOD;
    b /= 2;
    a = (a * a) % MOD;
  }
  return res;
}
void prefix(string &s) {
  int n = s.length();
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  string p;
  cin >> p;
  vector<int> y(m);
  for (int i = 0; i < m; i++) {
    cin >> y[i];
  }
  bool isValid = true;
  int l = p.length();
  pi.resize(l, 0);
  prefix(p);
  vector<int> pre(n + 2, 0);
  for (int i = 0; i < m; i++) {
    int start = y[i];
    int end = y[i] + l - 1;
    pre[start] += 1;
    pre[end + 1] -= 1;
    if (i == m - 1) break;
    if ((y[i + 1] > end) || (y[i + 1] == end - pi[l - 1] + 1)) {
    } else {
      isValid = false;
    }
  }
  bool allequal = true;
  for (long long int i = 0; i < l - 1; i++) {
    if (p[i] != p[i + 1]) {
      allequal = false;
      break;
    }
  }
  isValid = isValid | allequal;
  if (!isValid)
    cout << 0 << "\n";
  else {
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + pre[i];
    }
    int uncovered = 0;
    for (int i = 1; i <= n; i++) {
      if (pre[i] == 0) uncovered++;
    }
    long long int ans = power(26, uncovered);
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1, p = 0;
  do {
    solve();
    p++;
  } while (p < T);
  return 0;
}
