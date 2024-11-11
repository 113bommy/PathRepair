#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 100;
int n;
int ans[N];
int rec(int x) {
  int p = 1;
  while (p <= x) p <<= 1;
  p >>= 1;
  int k = p;
  for (int i = p; i <= x; ++i) {
    ans[--k] = i, ans[i] = k;
  }
  for (int i = x - p + 1; i < k; ++i)
    ans[i] = k - i + x - p, ans[k - i + x - p] = i;
  return min(x - p, k - 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int m = n;
  while (m > 0) m = rec(m);
  long long Ans = 0;
  for (int i = 0; i <= n; ++i) Ans += (ans[i] ^ i);
  cout << Ans << "\n";
  for (int i = 0; i <= n; ++i) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
