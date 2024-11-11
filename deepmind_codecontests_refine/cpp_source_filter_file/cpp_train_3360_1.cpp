#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n, x;
    cin >> n >> x;
    long long a[n];
    long long realSum = 0;
    int nums = 0;
    for (long long j = 0; j < n; j++) {
      cin >> a[j];
      realSum += a[j];
      if (x == a[j]) {
        nums++;
      }
    }
    long long sum = x * n;
    long long same = 1;
    for (long long j = 1; j < n; j++) {
      if (a[j] != a[j - 1]) {
        same = 0;
      }
    }
    if (same == 1 && a[0] == x) {
      cout << 0 << endl;
    } else {
      if (realSum == sum || nums == n - 1) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
  return 0;
}
