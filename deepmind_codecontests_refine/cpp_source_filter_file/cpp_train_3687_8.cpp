#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[100001], sum[100001], z = 1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum[i % k] += arr[i];
    if (z < i % k) z = i % k;
  }
  int mx = 2e8;
  int index;
  for (int i = 0; i <= z; i++) {
    if (mx > sum[i]) {
      mx = sum[i];
      index = i;
    }
  }
  cout << index + 1 << endl;
}
