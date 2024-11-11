#include <bits/stdc++.h>
using namespace std;
long long ans;
long long arr[200005][8];
long long a, b;
bool ok(long long mid, long long n, long long m) {
  long long mx = (1LL << m) - 1;
  long long cnt[mx + 1];
  for (int i = 0; i <= mx; i++) cnt[i] = 0;
  for (int i = 0; i < n; i++) {
    long long tem = 0;
    for (int j = 0; j < m; j++) {
      if (arr[i][j] >= mid) {
        tem = tem | (1LL << j);
      }
    }
    cnt[tem] = i + 1;
  }
  for (int i = 0; i < mx; i++) {
    for (int j = i; j < mx; j++) {
      if (cnt[i] && cnt[j]) {
        long long tem = i | j;
        if (tem == mx) {
          a = cnt[i];
          b = cnt[j];
          return true;
        }
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  ;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  }
  long long lo = 0;
  long long hi = 1e9;
  a = 1;
  b = 1;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (ok(mid, n, m)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}
