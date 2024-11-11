#include <bits/stdc++.h>
using namespace std;
pair<int_fast64_t, int_fast64_t> arr[100000];
int main() {
  int_fast64_t n, m, k, v, max1 = 10000000, j;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> k >> v;
    arr[i] = make_pair(k, v);
    while (k < n) {
      k = k + v;
    }
    if (max1 > k) {
      max1 = k;
      j = i;
    }
  }
  cout << j;
  return 0;
}
