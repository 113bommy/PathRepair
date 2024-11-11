#include <bits/stdc++.h>
using namespace std;
int a[200010];
int t, n, ans;
int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
int main() {
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  int k = 1;
  int i = 0;
  while (i < n) {
    if (k > a[i]) {
      i++;
    } else {
      i++;
      k++;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
