#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  int n, k;
  cin >> n >> k;
  long long arr[n + 1][k + 1];
  memset(arr, 0, sizeof(arr));
  for (int i = 1; i <= n; i++) {
    arr[i][0] = 1;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      for (int q = j; q <= n; q = q + j) {
        arr[q][i + 1] = (arr[q][i + 1] + arr[j][i]) % mod;
      }
    }
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum = (sum + arr[i][k - 1]) % mod;
  }
  cout << sum;
}
