#include <bits/stdc++.h>
using namespace std;
int arr[307];
int ans[307];
int add(int v) {
  int idx = 0;
  while (v > 0) {
    int x = min(9 - ans[idx], v);
    ans[idx] += x;
    v -= x;
    idx++;
  }
  return idx;
}
int rmv(int v) {
  int idx = 0;
  while (true) {
    if (v > 0 && ans[idx] != 9) break;
    v += ans[idx];
    ans[idx] = 0;
    idx++;
  }
  ans[idx]++;
  return v - 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) {
    int tmp = rmv(arr[i] - arr[i - 1]);
    add(tmp);
    int flag = 0;
    for (int j = 300; j >= 0; j--) {
      if (ans[j] && !flag) flag = 1;
      if (!flag) continue;
      cout << ans[j];
    }
    cout << endl;
  }
  return 0;
}
