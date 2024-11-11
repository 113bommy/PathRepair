#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
int a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  for (int i = 0; i <= 10000000; i++) {
    a[i + 1] += (a[i] / 2) % 2;
    if (a[i] % 2) ans++;
  }
  cout << ans;
}
