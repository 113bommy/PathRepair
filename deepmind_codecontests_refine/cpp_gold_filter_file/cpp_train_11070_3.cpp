#include <bits/stdc++.h>
using namespace std;
__int128 a[1000000], b[1000000];
int main() {
  long long n, c;
  cin >> n >> c;
  long long hi1, hi2;
  for (__int128 i = 0; i < n; i++) {
    cin >> hi1 >> hi2;
    a[i] = hi1, b[i] = hi2;
  }
  __int128 start1 = 1, finish1 = 4000000000000000000, mid1;
  do {
    mid1 = (start1 + finish1) / 2;
    __int128 tot = 0;
    for (__int128 i = 0; i < n; i++) {
      __int128 hi = mid1 * a[i];
      tot += hi / b[i] + 1;
    }
    if (tot >= c)
      finish1 = mid1 - 1;
    else
      start1 = mid1 + 1;
  } while (start1 <= finish1);
  bool is = false;
  __int128 on = 1;
  for (__int128 i = max(mid1 - 1, on); i <= mid1 + 1; i++) {
    __int128 tot = 0;
    for (__int128 j = 0; j < n; j++) {
      __int128 hi = i * a[j];
      tot += hi / b[j] + 1;
    }
    if (tot == c) {
      is = true;
      mid1 = i;
      break;
    }
  }
  if (!is) {
    cout << 0;
    return 0;
  }
  __int128 start2 = 1, finish2 = 4000000000000000000, mid2;
  do {
    mid2 = (start2 + finish2) / 2;
    __int128 tot = 0;
    for (__int128 i = 0; i < n; i++) {
      __int128 hi = mid2 * a[i];
      tot += hi / b[i] + 1;
    }
    if (tot > c)
      finish2 = mid2 - 1;
    else
      start2 = mid2 + 1;
  } while (start2 <= finish2);
  for (__int128 i = mid2 + 1; i >= max(mid2 - 1, on); i--) {
    __int128 tot = 0;
    for (__int128 j = 0; j < n; j++) {
      __int128 hi = i * a[j];
      tot += hi / b[j] + 1;
    }
    if (tot == c) {
      mid2 = i;
      break;
    }
  }
  long long f = mid2 - mid1 + 1;
  if (f >= 2000000000000000000)
    cout << -1;
  else
    cout << f;
  return 0;
}
