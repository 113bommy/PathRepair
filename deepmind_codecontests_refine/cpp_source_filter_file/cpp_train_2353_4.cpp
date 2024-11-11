#include <bits/stdc++.h>
using namespace std;
int a[200002];
int b[200002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, q, l, r;
  cin >> n >> k >> q;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    a[l]++;
    a[r + 1]--;
  }
  for (int i = 1; i < 200002; ++i) {
    a[i] += a[i - 1];
    if (a[i] == k) b[i] = 1;
  }
  for (int i = 1; i < 200002; ++i) {
    b[i] += b[i - 1];
  }
  for (int i = 0; i < q; ++i) {
    cin >> l >> r;
    cout << b[r] - b[l - 1] << "\n";
  }
}
