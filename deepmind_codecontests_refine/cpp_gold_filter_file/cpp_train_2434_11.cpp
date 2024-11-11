#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int main() {
  int n, q;
  cin >> n >> q;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  vector<int> ref(n + 3);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    ref[l]++;
    ref[r + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    ref[i] += ref[i - 1];
  }
  vector<int> order;
  for (int i = 1; i <= n; i++) {
    order.push_back(ref[i]);
  }
  long long int ans = 0;
  sort(order.rbegin(), order.rend());
  for (int i = 0; i < order.size(); i++) {
    ans += 1ll * a[i] * order[i];
  }
  cout << ans << endl;
}
