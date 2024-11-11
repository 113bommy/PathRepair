#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int t[50];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  int sum = 0;
  for (int i = 1; i <= k; i++) {
    cin >> t[i];
    sum += t[i];
  }
  sort(t + 1, t + k + 1);
  int mx = 0;
  for (int i = 0; i <= n; i++) {
    int s = (k + 1) * i;
    int le = m - sum * i;
    if (le < 0) break;
    for (int j = 1; j <= k; j++) {
      for (int k = n - i; k > 0; k--) {
        if (le >= t[j]) {
          le -= t[j];
          s++;
        }
      }
    }
    mx = max(mx, s);
  }
  cout << mx;
}
