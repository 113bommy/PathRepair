#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long ans = 999999999, index = 0;
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    if (a[i] != -1) {
      for (int j = i; j < n; j += (k)) {
        sum += a[j];
        a[j] = -1;
      }
      if (sum <= ans) {
        index = i;
        ans = sum;
      }
    }
  }
  cout << index + 1 << endl;
  return 0;
}
