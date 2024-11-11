#include <bits/stdc++.h>
using namespace std;
long long l, w, k;
int main() {
  cin >> l >> w >> k;
  if (k > l + w - 2) {
    cout << -1;
    return 0;
  }
  if (k + 1 <= max(l, w)) {
    long long e = max(l, w);
    long long t = min(l, w);
    long long j = (t / (k + 1)) * max(l, w);
    long long k = (e / (k + 1)) * min(l, w);
    if (j > k)
      cout << j;
    else
      cout << k;
  } else {
    long long e = min(l, w);
    cout << (e / (k + 2 - max(l, w)));
  }
  return 0;
}
