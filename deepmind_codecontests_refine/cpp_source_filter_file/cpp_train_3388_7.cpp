#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
int a[300000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int l = 0, r = 0, j = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (j < i) {
      j = i;
      cnt = 0;
    }
    while (j < n) {
      int temp = cnt + !a[j];
      if (temp > k) break;
      cnt = temp;
      ++j;
    }
    if (j - i > r - l) {
      l = i;
      r = j;
    }
    if (cnt > 0) cnt -= !a[i];
  }
  for (int i = l; i <= r; ++i) a[i] = 1;
  cout << r - l << endl;
  for (int i = 0; i < n; ++i) cout << a[i] << " ";
  return 0;
}
