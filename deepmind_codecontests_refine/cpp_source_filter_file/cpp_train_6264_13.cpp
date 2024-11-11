#include <bits/stdc++.h>
using namespace std;
long long mmin() { return LLONG_MAX; }
template <typename T, typename... Args>
T mmin(T a, Args... args) {
  return min(a, mmin(args...));
}
long long mmax() { return LLONG_MIN; }
template <typename T, typename... Args>
T mmax(T a, Args... args) {
  return max(a, mmax(args...));
}
long long gcd() { return 0ll; }
template <typename T, typename... Args>
T gcd(T a, Args... args) {
  return __gcd(a, (__typeof(a))gcd(args...));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  long long curr, arr[200005], barr[200005], l, r;
  cin >> n;
  long long idx = -1, ma = -1;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    barr[i] = arr[i];
    if (arr[i] > ma) {
      ma = arr[i];
      idx = i;
    }
  }
  sort(arr, arr + n);
  long long flg;
  l = max(1ll * 0, idx - 1);
  r = min(n - 1, idx + 1);
  curr = n - 2;
  flg = 0;
  while (1) {
    if (l < 0 || r > n - 1) break;
    if (barr[l] == arr[curr]) {
      l--;
      curr--;
    } else if (barr[r] == arr[curr]) {
      r++;
      curr--;
    } else {
      flg = 1;
      break;
    }
  }
  if (flg == 0)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}
