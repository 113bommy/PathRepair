#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  vector<int> arr(n);
  int add = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    if (arr[i] == 0 && i != s - 1) {
      arr[i] = -1;
      ++add;
    }
  }
  if (arr[s - 1] != 0) {
    ++add;
    arr[s - 1] = -1;
  }
  if (n == 1) {
    cout << add << '\n';
    return 0;
  }
  vector<int> cnt(n), suff(n + 1);
  for (int i = 0; i < n; ++i)
    if (arr[i] > 0) cnt[arr[i]]++;
  suff[n - 1] = cnt[n - 1];
  for (int i = n - 2; i >= 0; --i) suff[i] = suff[i + 1] + cnt[i];
  int cnt0 = 0;
  int ans = 1e9;
  for (int mx = 1; mx < n; ++mx) {
    int cur = suff[mx + 1] + max(0, min(cnt0, cnt0 - suff[mx + 1] - add));
    ans = min(ans, cur);
    cnt0 += (cnt[mx] == 0);
  }
  cout << ans + add << '\n';
}
