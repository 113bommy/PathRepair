#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int find(long long int l, long long int r, long long int t,
                   long long int N) {
  long long int mid = l + (r - l) / 2;
  if (mid == t)
    return N;
  else if (mid < t)
    return find(mid + 1, r, t, N - 1);
  else if (mid > t)
    return find(1, mid - 1, t, N - 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, k;
  cin >> n >> k;
  long long int size = 1;
  for (long long int i = 1; i < n; ++i) size = size * 2 + 1;
  cout << find(1, size, k, n);
  return 0;
}
