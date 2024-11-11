#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[5005], b[5005];
const int MX = 35000;
bool npr[MX];
int pr[MX], psz = 0;
bool bad[MX];
pair<int, int> cnt(int k) {
  int gd = 0, bd = 0;
  int k1 = k;
  for (int i = 0; i < psz && pr[i] * pr[i] <= k1; ++i) {
    while (k % pr[i] == 0) {
      k /= pr[i];
      if (bad[i])
        bd++;
      else
        gd++;
    }
  }
  if (k != 1) {
    int pos = lower_bound(b, b + m, k) - b;
    if (pos < psz && b[pos] == k)
      bd++;
    else
      gd++;
  }
  return make_pair(gd, bd);
}
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int j = 0; j < m; ++j) scanf("%d", &b[j]);
  for (int i = 2; i < MX; ++i)
    if (!npr[i]) {
      pr[psz++] = i;
      for (int j = i + i; j < MX; j += i) npr[j] = 1;
    }
  for (int i = 0; i < psz; ++i) {
    int pos = lower_bound(b, b + m, pr[i]) - b;
    if (pos < m && b[pos] == pr[i]) bad[i] = 1;
  }
  for (int k = n - 1; k >= 0; --k) {
    int g = a[0];
    for (int i = 1; i <= k; ++i) g = gcd(g, a[i]);
    pair<int, int> pr = cnt(g);
    if (pr.first <= pr.second)
      for (int i = 0; i <= k; ++i) a[i] /= g;
  }
  int ans = 0;
  pair<int, int> pr;
  for (int i = 0; i < n; ++i) {
    pr = cnt(a[i]);
    ans += pr.first - pr.second;
  }
  cout << ans << endl;
  return 0;
}
