#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long k;
  cin >> n >> k;
  int a[n];
  int i;
  for (i = 0; i < n; i++) cin >> a[i];
  if (k >= n) {
    int m = a[0];
    for (i = 1; i < n; i++) {
      m = max(m, a[i]);
    }
    cout << m;
  } else {
    int j;
    for (j = 1; j < k + 1; j++) {
      if (a[j % n] > a[i]) break;
    }
    if (j == k + 1) {
      cout << a[0];
      exit(0);
    }
    for (i = 1; i < n; i++) {
      int m = a[i];
      for (j = i + 1; j < i + k; j++) {
        if (a[j % n] > a[i]) break;
      }
      if (j == i + k) break;
    }
    cout << a[i];
  }
}
