#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k, cnt[N], mn = INT_MAX;
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    mn = min(mn, u);
    cnt[max(1, u - k)]++;
    cnt[u + 1]--;
  }
  for (int i = 1; i <= N - 5; i++) cnt[i] += cnt[i - 1];
  for (int i = mn; i > k; i--) {
    int sum = 0;
    for (int j = i; j + k - 1 <= N - 5; j += i) sum += cnt[j];
    if (sum == n) {
      cout << i << "\n";
      exit(0);
    }
  }
  cout << mn << "\n";
}
