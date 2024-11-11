#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005], kol[1000005], pric[1000005], dp[1000005];
int ferm[1000005], n;
int maxi(int k) {
  int ans = 0;
  while (k > 0) {
    ans = max(ans, ferm[k]);
    k -= (k & (-k));
  }
  return ans;
}
void add(int val, int k) {
  while (k <= n) {
    ferm[k] = max(ferm[k], val);
    k += (k & (-k));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    kol[a[i]] = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int l = 0;
  for (int i = 0; i < n; i++) {
    pric[l] = kol[b[i]] + 1;
    l++;
  }
  reverse(pric, pric + n);
  for (int i = 0; i < n; i++) {
    dp[i] = maxi(pric[i] - 1) + 1;
    add(dp[i], pric[i]);
  }
  cout << *max_element(dp, dp + n);
}
