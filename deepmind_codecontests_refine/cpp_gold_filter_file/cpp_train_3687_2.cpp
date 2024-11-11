#include <bits/stdc++.h>
using namespace std;
int a[100500], n, k, sum[100500];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i % k] += a[i];
  }
  int mn = (int)1e9, pos;
  for (int i = 0; i < k; i++) {
    if (mn > sum[i]) {
      mn = sum[i];
      pos = i % k + 1;
    }
  }
  cout << pos;
  return 0;
}
