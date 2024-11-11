#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  long long ans = 0;
  cin >> n >> d;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  int h = 0;
  for (int i = 0; i < n - 2; ++i) {
    while (h < n - 1 && v[h + 1] <= v[i] + d) ++h;
    long long dif = h - i;
    ans += (dif * (dif - 1)) / 2;
  }
  cout << ans;
}
