#include <bits/stdc++.h>
using namespace std;
int n, arr[20000];
int count(int k) {
  long sum, m = -1000 * 20000;
  for (int j = 0; j < k; j++) {
    sum = 0;
    for (int l = j; l < n; l += k) sum += arr[l];
    if (sum > m) m = sum;
  }
  return m;
}
int main() {
  cin >> n;
  long max, end = (int)(sqrt(n)) + 1, sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  max = sum;
  if (n > 5)
    for (int i = 2; i < n - 1; i++) {
      if (!(n % i) && (n / i) > 2) {
        long res = count(i);
        if (res > max) max = res;
      }
    }
  cout << max;
  return 0;
}
