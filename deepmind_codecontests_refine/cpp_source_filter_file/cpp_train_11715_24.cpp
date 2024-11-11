#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18, MOD = 1e9 + 7, MOD2 = 1e6 + 3;
long long sum, a[2000001], d[100], n, m, k, last[200];
string s;
int main() {
  cin >> m >> k;
  cin >> s;
  n = s.length();
  fill(last, last + k, -1);
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - 'a';
    last[a[i]] = i;
  }
  for (int i = 0; i < k; i++) a[n + i] = i;
  sort(a + n, a + n + k, [&](int a, int b) { return last[a] < last[b]; });
  for (int i = n + k; i < m; i++) a[i] = a[i - k];
  for (int i = 0; i < n + m; i++) {
    long long nw = sum + 1;
    if (nw == MOD) nw -= MOD;
    sum += MOD + nw - d[a[i]];
    if (sum >= MOD) sum -= MOD;
    if (sum >= MOD) sum -= MOD;
    d[a[i]] = nw;
  }
  cout << (sum + 1) % MOD << endl;
}
