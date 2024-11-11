#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
long long arr[500005];
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int arr[105][105];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        arr[i][j] = k;
      } else {
        arr[i][j] = 0;
      }
      cout << arr[i][j];
    }
    cout << "\n";
  }
  return 0;
}
