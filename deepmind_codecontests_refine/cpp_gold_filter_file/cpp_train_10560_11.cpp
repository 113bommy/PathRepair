#include <bits/stdc++.h>
using namespace std;
long long us[1000], ans[1000], a[1000];
int main() {
  long long n, k = 0, i, j, mi, s, m;
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    mi = 1000;
    for (j = 1; j <= n; j++) {
      if (!us[j] && mi > a[j]) s = j, mi = a[j];
    }
    us[s] = 1;
    ans[s] = i % 2;
  }
  for (i = 1; i <= n; i++) cout << ans[i] << ' ';
}
