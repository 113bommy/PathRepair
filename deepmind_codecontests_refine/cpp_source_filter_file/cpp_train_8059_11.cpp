#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 3;
int n, k, q, sum[Maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> q;
  for (int i = (int)(1); i < (int)(n + 1); ++i) {
    char ch;
    cin >> ch;
    sum[i] = (ch == '0');
    sum[i] += sum[max(i - k, 0)];
  }
  for (int i = (int)(0); i < (int)(q); ++i) {
    int l, r;
    cin >> l >> r;
    int s = (r - l + 1) / k;
    int ans = sum[r] - sum[max(l - k, 0)];
    for (int i = (int)(1); i < (int)(k); ++i)
      ans += s - (sum[max(r - i, 0)] - sum[max(l - i, 0)]);
    cout << ans << endl;
  }
  return 0;
}
