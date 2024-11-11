#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int pre = 0;
  for (int i = 0; i < k; i++) {
    pre += a[i];
  }
  int minval = pre;
  int index = 0;
  for (int i = 1; i < n - k + 1; i++) {
    pre = pre - a[i - 1] + a[k + 1];
    if (minval > pre) {
      index = i;
      minval = pre;
    }
  }
  cout << index << endl;
  return 0;
}
