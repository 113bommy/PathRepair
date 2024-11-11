#include <bits/stdc++.h>
using namespace std;
long long int calculation(long long int n) {
  if (n < 0) return 0;
  return (n * (n + 1)) / 2;
}
long long int A[100005];
int main() {
  long long int k, n, tut = 0;
  cin >> k >> n;
  long long int b = 0, e = 10000000000;
  while (b <= e) {
    long long int mid = (b + e) / 2;
    if (calculation(mid) - calculation(mid - n) <= k) {
      tut = max(tut, mid);
      b = mid + 1;
    } else
      e = mid - 1;
  }
  long long int temp = k - calculation(tut) - calculation(tut - n);
  for (int i = n; i >= 1; i--) {
    A[i] = tut;
    tut--;
  }
  for (int i = n; i >= 2; i--) {
    A[i] += min(A[i - 1] - 1, temp);
    temp -= min(A[i - 1] - 1, temp);
  }
  A[1] += temp;
  bool ans = true;
  for (int i = 2; i <= n; i++) {
    if (A[i] <= A[i - 1] || A[i] > 2 * A[i - 1]) ans = false;
  }
  if (!ans) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << A[i] << " ";
    cout << endl;
  }
  return 0;
}
