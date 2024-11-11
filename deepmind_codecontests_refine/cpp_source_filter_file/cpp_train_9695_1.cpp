#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n, a[maxn];
int res = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= n; i += 2) {
    res += a[i] - a[i - 1];
  }
  cout << res;
}
