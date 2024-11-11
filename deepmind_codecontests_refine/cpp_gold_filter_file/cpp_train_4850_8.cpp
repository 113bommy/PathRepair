#include <bits/stdc++.h>
using namespace std;
long long mx(int a[], long long n, long long k) {
  long long sum = 2;
  int lasti = 0;
  int curr = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 0) lasti = i;
    if (i - curr - 1 == k) {
      if (lasti == curr) return n + 1;
      sum++;
      curr = lasti;
    }
  }
  return sum;
}
long long bsearch(int a[], long long n, long long k, long long l, long long r) {
  if (l == r) {
    if (mx(a, n, l) <= k)
      return l;
    else
      return -1;
  } else {
    long long mid = l + (r - l) / 2;
    if (mx(a, n, mid) <= k) {
      return bsearch(a, n, k, l, mid);
    } else {
      return bsearch(a, n, k, mid + 1, r);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt = 1;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[n];
    for (int i = 0; i < n; i++) {
      a[i] = s.at(i) - '0';
    }
    long long ans = bsearch(a, n, k, 0, n);
    cout << ans << endl;
  }
  return 0;
}
