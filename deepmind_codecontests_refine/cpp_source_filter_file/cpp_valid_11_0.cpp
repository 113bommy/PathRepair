#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 10000;
const long long mod = 1000000007;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n), e(n);
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    int qtd[] = {0, 0, 0, 0, 0};
    for (char c : str) {
      qtd[c - 'a']++;
    }
    a[i] = 2 * qtd[0] - str.length();
    b[i] = 2 * qtd[1] - str.length();
    c[i] = 2 * qtd[2] - str.length();
    d[i] = 2 * qtd[3] - str.length();
    e[i] = 2 * qtd[4] - str.length();
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  sort(d.rbegin(), d.rend());
  sort(e.rbegin(), e.rend());
  int ans = 0;
  int sum = 0, i = 0;
  while (i < n && sum + a[i] > 0) {
    sum += a[i];
    i++;
  }
  ans = max(ans, i);
  sum = 0, i = 0;
  while (i < n && sum + b[i] > 0) {
    sum += b[i];
    i++;
  }
  ans = max(ans, i);
  sum = 0, i = 0;
  while (i < n && sum + c[i] > 0) {
    sum += c[i];
    i++;
  }
  ans = max(ans, i);
  sum = 0, i = 0;
  while (i < n && sum + d[i] > 0) {
    sum += d[i];
    i++;
  }
  ans = max(ans, i);
  sum = 0, i = 0;
  while (i < n && sum + d[i] > 0) {
    sum += d[i];
    i++;
  }
  ans = max(ans, i);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
