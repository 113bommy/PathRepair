#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> k >> n;
  long long cur = (n * (n + 1)) / 2;
  vector<int> ans(n);
  iota(ans.begin(), ans.end(), 1);
  if (cur > k) {
    cout << "NO";
    return 0;
  }
  if ((k - cur) / n > 0) {
    int add = (k - cur) / n;
    for (int i = 0; i < int(n); i++) ans[i] += add;
  }
  cur = 0;
  for (int i = 0; i < int(n); i++) cur += ans[i];
  int i = n - 1;
  int left = k - cur;
  while (i > 0) {
    if (2 * ans[i - 1] < left + ans[i]) {
      left += ans[i];
      ans[i] = 2 * ans[i - 1];
      left -= ans[i];
    } else {
      ans[i] += left;
      break;
    }
    --i;
  }
  cur = 0;
  for (int i = 0; i < int(n); i++) cur += ans[i];
  if (cur == k) {
    cout << "YES\n";
    for (int i = 0; i < int(n); i++) cout << ans[i] << ' ';
  } else
    cout << "NO";
  return 0;
}
