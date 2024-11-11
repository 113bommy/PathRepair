#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, a[maxn];
int q[maxn], h, t;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  h = 0;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      ans += a[i] / 2;
      continue;
    }
    if (!h) {
      q[++h] = i;
    } else {
      if ((i - q[h]) % 2 == 0) {
        q[++h] = i;
        continue;
      }
      ans += (a[i] + a[q[h]]) / 2;
      --h;
    }
  }
  while (h) {
    ans += a[q[h]] / 2, --h;
  }
  cout << ans;
  return 0;
}
