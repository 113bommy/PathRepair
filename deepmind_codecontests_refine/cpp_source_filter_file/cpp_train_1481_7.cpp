#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) { return a < b ? a : b; }
long long Evil(long long* arr, long long n, long long index) {
  if (index == -1) return 0;
  long long a[n];
  long long b[n];
  long long s1 = 0, s2 = 0;
  for (long long i = 0; i < n; i++) {
    if ((arr[i] >> index) & 1) {
      a[s1] = arr[i];
      s1++;
    } else {
      a[s2] = arr[i];
      s2++;
    }
  }
  if (s1 == n || s2 == n) {
    return Evil(arr, n, index - 1);
  } else {
    long long ans1 = Evil(a, s1, index - 1);
    long long ans2 = Evil(b, s2, index - 1);
    return 1 << index + min(ans1, ans2);
  }
}
int main() {
  long long n;
  cin >> n;
  long long* arr = new long long[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << Evil(arr, n, 31);
  return 0;
}
