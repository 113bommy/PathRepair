#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, z;
int a[maxn];
int ans;
int main() {
  cin >> n >> z;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n);
  int l = 1, r = (n + 1) / 2;
  while (r <= n) {
    if (a[r] - a[l] >= z) {
      ans++;
      l++;
    }
    r++;
  }
  cout << ans;
  return 0;
}
