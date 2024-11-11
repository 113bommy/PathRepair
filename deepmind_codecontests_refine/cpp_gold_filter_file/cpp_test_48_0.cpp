#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
long long merge(long long arr[], long long l, long long mid, long long r) {
  long long ans = 0;
  long long n1 = mid - l + 1;
  long long n2 = r - mid;
  long long a[n1];
  long long b[n2];
  for (long long i = 0; i < n1; i++) {
    a[i] = arr[l + i];
  }
  for (long long i = 0; i < n2; i++) {
    b[i] = arr[mid + 1 + i];
  }
  long long i = 0;
  long long j = 0;
  long long k = l;
  while (i < n1 && j < n2) {
    if (a[i] <= b[j]) {
      arr[k] = a[i];
      k++;
      i++;
    } else {
      ans += n1 - i;
      arr[k] = b[j];
      k++;
      j++;
    }
  }
  while (i < n1) {
    arr[k] = a[i];
    k++;
    i++;
  }
  while (j < n2) {
    arr[k] = b[j];
    k++;
    j++;
  }
  return ans;
}
long long inversion_count(long long arr[], long long l, long long r) {
  long long ans = 0;
  if (l < r) {
    long long mid = (l + r) / 2;
    ans += inversion_count(arr, l, mid);
    ans += inversion_count(arr, mid + 1, r);
    ans += merge(arr, l, mid, r);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long v[n];
    for (long long i = 0; i < n; i++) cin >> v[i];
    bool ans = false;
    long long inv = inversion_count(v, 0, n - 1);
    if (inv % 2 == 0)
      ans = true;
    else {
      sort(v, v + n);
      for (long long i = 0; i < n - 1; i++)
        if (v[i] == v[i + 1]) ans = true;
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
  return 0;
}
