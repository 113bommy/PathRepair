#include <bits/stdc++.h>
using namespace std;
int a[10010], b[100010], c[10010];
long long mn = 1e9, mx = -1e9, ans, cnt, sm;
bool ok, okk, used[1000010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      ans++;
    } else {
      ans += ((a[i] - 1) * (i + 1) + 1);
    }
  }
  cout << ans;
  return 0;
}
