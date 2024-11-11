#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, l = 1;
  cin >> n >> m;
  long long c = m, j = 1;
  long long ans[100000];
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 1; i <= c; i++) {
    if (m - i < 0) break;
    if (a[j] == i)
      j++;
    else {
      if (m - i >= 0) {
        ans[l] = i;
        m -= i;
        l++;
      }
    }
  }
  cout << l - 1 << endl;
  for (int i = 1; i <= l - 1; i++) cout << ans[i] << " ";
  return 0;
}
