#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  int arr[100005];
  int toUse[100005];
  memset(toUse, -1, sizeof(toUse));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    toUse[arr[i]] = i;
  }
  if (arr[0] > 1) {
    cout << -1;
    return 0;
  }
  vector<int> ans;
  int prev;
  if (arr[0] == 0) {
    for (prev = 1;; prev++) {
      if (toUse[prev] < 0) break;
    }
    ans.push_back(prev);
    toUse[prev] = 9999999;
  } else if (arr[0] == 1) {
    for (prev = 1;; prev++) {
      if (toUse[prev] < 0) break;
    }
    ans.push_back(prev);
    toUse[prev] = 9999999;
  }
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) {
      if (toUse[arr[i - 1]] > i) {
        cout << -1;
        return 0;
      }
      int push = arr[i - 1];
      ans.push_back(push);
      toUse[push] = 9999999;
      prev = push;
    } else {
      int push = prev + 1;
      while (toUse[push] >= i) push++;
      ans.push_back(push);
      toUse[push] = 9999999;
      prev = push;
    }
  }
  for (auto& x : ans) cout << x << " ";
  return 0;
}
