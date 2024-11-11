#include <bits/stdc++.h>
using namespace std;
const int infint = INT_MAX;
const long long infll = LLONG_MAX;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  long long sum = 0;
  vector<long long> arr(n), cp(n);
  int nzero = -1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cp[i] = arr[i];
    sum += arr[i];
    if (arr[i] > 0) nzero = i;
  }
  long long l = nzero + 1, r = 1e13, mid = 0;
  while (l + 1 < r) {
    mid = (l + r) / 2;
    arr = cp;
    long long lSum = 0;
    int j = nzero;
    long long t = mid;
    for (int i = 0; i < m; i++) {
      while (j > 0 && arr[j] <= 0) j--;
      long long tTime = j + 1;
      for (; j >= 0 && tTime < mid; j--) {
        lSum += min(arr[j], max(0LL, mid - tTime));
        long long oldArr = arr[j];
        arr[j] -= min(arr[j], max(0LL, mid - tTime));
        tTime += min(max(0LL, mid - tTime), oldArr);
        if (tTime >= mid) break;
      }
    }
    if (lSum >= sum) {
      r = mid;
    } else
      l = mid;
  }
  cout << r;
  return 0;
}
