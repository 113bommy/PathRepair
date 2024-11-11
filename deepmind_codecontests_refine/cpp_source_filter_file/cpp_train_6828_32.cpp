#include <bits/stdc++.h>
using namespace std;
int arr[100005], ans[100005][400], n;
int dpIteration(int p, int k) {
  if (p > n) 0;
  if (ans[p][k] != -1) return ans[p][k];
  return ans[p][k] = 1 + dpIteration(p + arr[p] + k, k);
}
int main() {
a:
  ios::sync_with_stdio(0);
  cin >> n;
  memset(ans, -1, sizeof(ans));
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int q;
  cin >> q;
  while (q--) {
    int p, k;
    cin >> p >> k;
    if (k < 400) {
      cout << dpIteration(p, k) << '\n';
    } else {
      int co = 0;
      while (p <= n) {
        p = p + arr[p] + k;
        co++;
      }
      cout << co << '\n';
    }
  }
}
