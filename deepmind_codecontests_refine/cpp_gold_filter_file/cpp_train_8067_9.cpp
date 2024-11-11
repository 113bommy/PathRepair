#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int arr[MAX], arr2[MAX], sor[MAX], last[MAX], dp1[MAX], dp2[MAX], freq[MAX];
int n, t;
int main() {
  memset(last, -1, sizeof(last));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> t;
  int sz = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    freq[arr[i]]++;
    arr2[i] = arr[i];
    sor[sz++] = arr[i];
  }
  sort(sor, sor + sz);
  for (int i = n; i < n * 500; ++i) arr2[i] = arr2[i - n];
  for (int i = 0; i < n * 500; ++i) {
    dp1[i] = 1;
    for (int j = 0; j < sz; ++j) {
      if (sor[j] <= arr2[i] && last[sor[j]] != -1)
        dp1[i] = max(dp1[i], dp1[last[sor[j]]] + 1);
    }
    last[arr2[i]] = i;
  }
  if (t <= 500) {
    int ans = 0;
    for (int i = 0; i < n * t; ++i) ans = max(ans, dp1[i]);
    return cout << ans << "\n", 0;
  }
  memset(last, -1, sizeof(last));
  for (int i = n * 200 - 1; i >= 0; --i) {
    dp2[i] = 1;
    for (int j = 0; j < sz; ++j) {
      if (sor[j] >= arr2[i] && last[sor[j]] != -1)
        dp2[i] = max(dp2[i], dp2[last[sor[j]]] + 1);
    }
    last[arr2[i]] = i;
  }
  int ans = 0;
  for (int i = 0; i < n * 200; ++i) {
    int copies = i / n + 1;
    for (int j = 0; j < n; ++j) {
      if (arr2[j] < arr2[i]) continue;
      int need = t - copies - 200;
      ans = max(ans, dp1[i] + need * freq[arr2[i]] + dp2[j]);
    }
  }
  return cout << ans << "\n", 0;
}
