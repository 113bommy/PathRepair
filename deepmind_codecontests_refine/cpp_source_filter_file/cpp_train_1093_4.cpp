#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
int a[N];
int n, k;
bool f(long long x) {
  int l = 1;
  int r = n;
  int k1 = k;
  while (l <= r) {
    while (a[l] + a[r] > x && l != r) {
      r--;
      k1--;
    }
    l++;
    r--;
    k1--;
  }
  if (k1 >= 0)
    return true;
  else
    return false;
}
int main() {
  srand(time(NULL));
  cin >> n >> k;
  int sum = 0;
  int mx = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  long long l = mx;
  long long r = sum;
  long long p;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (f(mid)) {
      r = mid - 1;
      p = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << p;
  return 0;
}
