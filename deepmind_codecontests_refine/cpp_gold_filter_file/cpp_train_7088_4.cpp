#include <bits/stdc++.h>
using namespace std;
int a[100001];
bool v[100001];
int gcd(int a, int b) {
  if (b == 0) return a;
  return a % b == 0 ? b : gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int i, j;
  int n, k;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= k;
  }
  int g = k;
  for (i = 0; i < n; i++) g = gcd(g, a[i]);
  int cur = 0;
  for (i = 0; i < k; i++) {
    v[cur] = true;
    cur = (cur + g) % k;
  }
  int ans = 0;
  for (i = 0; i < k; i++)
    if (v[i]) ans++;
  cout << ans << '\n';
  for (i = 0; i < k; i++)
    if (v[i]) cout << i << ' ';
}
