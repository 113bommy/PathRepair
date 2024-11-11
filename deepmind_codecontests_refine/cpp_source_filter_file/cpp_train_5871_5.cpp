#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[(2 * n - 1)], sum = 0, sum1 = 0;
  for (int i = 0; i < (2 * n - 1); i++) {
    cin >> a[i];
  }
  for (int i = 0; i < (2 * n - 1); i++) {
    sum = sum + abs(a[i]);
  }
  long long k = 0;
  for (int i = 0; i < (2 * n - 1); i++) {
    if (a[i] < 0) {
      k++;
    }
  }
  for (int i = 0; i < (2 * n - 1); i++) {
    a[i] = abs(a[i]);
  }
  sort(a, a + (2 * n - 1));
  if (k == 0) {
    cout << sum;
  } else {
    if (n % 2 == 0 && (n - k) % 2 == 0) {
      sum = sum - 2 * a[0];
      cout << sum;
    } else {
      cout << sum;
    }
  }
  return 0;
}
