#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, k, i, j, pos = 0, neg = 0, p, n, max = 0;
  cin >> N >> k;
  int a[N], b[N];
  for (i = 0; i < N; i++) {
    cin >> a[i];
    b[i] = a[i];
    if (a[i] == 1) {
      pos++;
    } else {
      neg++;
    }
  }
  for (i = 0; i < k; i++) {
    p = 0;
    n = 0;
    for (j = i; j < N; j += k) {
      if (a[j] == 1) {
        p++;
      } else {
        n++;
      }
    }
    if (abs((pos - p) - (neg - n)) > max) {
      max = abs((pos - p) - (neg - n));
    }
  }
  cout << max;
  return 0;
}
