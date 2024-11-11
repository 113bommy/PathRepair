#include <bits/stdc++.h>
using namespace std;
char t[10001][10001] = {0};
int getBits(int x) {
  x = x - ((x >> 1) & 0x5555);
  x = (x & 0x3333) + ((x >> 2) & 0x3333);
  x = (x + (x >> 4)) & 0x0F0F;
  return (x * 0x0101) >> 8;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i <= 10000; i++) {
    for (int j = i + 1; j <= 10000; j++) {
      int tmp = i ^ j;
      t[i][j] = getBits(tmp);
    }
  }
  long long p[10001] = {0};
  for (int i = 0; i < n; i++) {
    p[a[i]]++;
  }
  if (k == 0) {
    int ans = 0;
    for (int i = 0; i <= 10000; i++) ans += p[i] * (p[i] - 1) / 2;
    cout << ans << endl;
    return;
  }
  long long ans = 0;
  for (int i = 0; i <= 10000; i++)
    for (int j = i + 1; j <= 10000; j++)
      if (t[i][j] == k) ans += p[i] * p[j];
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
