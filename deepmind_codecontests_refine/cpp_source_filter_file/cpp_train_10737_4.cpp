#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, j = 0;
  cin >> n;
  vector<int> arr;
  arr.push_back(1);
  cin >> x;
  for (int i = 1; i < n; i++) {
    cin >> y;
    if (x == y) {
      arr[j]++;
    } else {
      j++;
      arr.push_back(1);
      x = y;
    }
  }
  int k1 = 0;
  arr.resize(j);
  int k, ans = arr[0];
  for (int i = 1; i < j + 1; i++) {
    k = min(arr[i], arr[i - 1]);
    ans = max(k, ans);
  }
  cout << 2 * ans;
  return 0;
}
