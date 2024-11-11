#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, d, m;
int a[maxn];
int br1, br2;
long long provjeri(int x) {
  long long sol = 0;
  if (!x) {
    for (int i = 0; i < n; i++) {
      sol += a[i];
    }
    return sol;
  }
  for (int i = 0; i < x; i++) {
    sol += a[n - 1 - i];
  }
  int pos = n - x - 1;
  int br = (x - 1) * d;
  while (pos > -1 && a[pos] > m) {
    br--;
    pos--;
  }
  for (int i = br; i <= pos; i++) {
    sol += a[i];
  }
  return sol;
}
long long binary() {
  if (!br2) {
    return provjeri(0);
  }
  int lo, hi, mid;
  lo = min((br2 - 1 + d) / (d + 1) + 1, hi);
  hi = min(br2, (n + d) / (d + 1));
  if (lo > hi) {
    return 0;
  }
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (provjeri(mid) > provjeri(mid + 1)) {
      hi = mid;
    } else {
      assert(provjeri(mid) != provjeri(mid + 1));
      lo = mid + 1;
    }
  }
  return provjeri(lo);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d >> m;
  long long drugo = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > m) {
      br2++;
    } else {
      drugo += a[i];
      br1++;
    }
  }
  sort(a, a + n);
  for (int i = 0; i < (br2 + d) / (d + 1); i++) {
    drugo += a[n - i - 1];
  }
  cout << max(binary(), drugo) << '\n';
  return 0;
}
