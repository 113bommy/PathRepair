#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
long long n, m;
vector<long long> arr(N);
bool ok(long long maxa) {
  long long prev = 0;
  int k;
  for (int i = 0; i < n; i++) {
    if (prev <= arr[i]) {
      k = m - arr[i] + prev;
      if (k > maxa) {
        prev = arr[i];
      }
    } else {
      k = prev - arr[i];
      if (k > maxa) {
        return 0;
      }
    }
  }
  return 1;
}
int main() {
  cin >> n;
  cin >> m;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long l, r;
  l = 0, r = m;
  long long mid;
  while (l < r) {
    mid = l + (r - l) / 2;
    if (ok(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (ok(mid)) {
    cout << mid << endl;
  } else {
    cout << mid + 1 << endl;
  }
  return 0;
}
