#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
bool func(long long i, long long n, long long m) {
  long long k = max(0ll, i - m);
  if (k > 1e10) return false;
  n = n - (k * (k - 1) / 2);
  if (n > i) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long l = 1, h = n, mid;
  while (l <= h) {
    mid = h - (h - l) / 2;
    if (func(mid, n, m))
      l = mid + 1;
    else
      h = mid - 1;
  }
  cout << l;
}
