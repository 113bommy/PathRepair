#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n;
  cin >> n;
  unsigned long long a[30][30];
  for (unsigned long long i = 0; i < n; i++) {
    for (unsigned long long j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  unsigned long long r[30];
  unsigned long long c[30];
  for (unsigned long long i = 0; i < 30; i++) {
    r[i] = 0;
    c[i] = 0;
  }
  for (unsigned long long i = 0; i < n; i++) {
    for (unsigned long long j = 0; j < n; j++) {
      r[i] += a[j][i];
    }
  }
  for (unsigned long long i = 0; i < n; i++) {
    for (unsigned long long j = 0; j < n; j++) {
      c[i] += a[i][j];
    }
  }
  unsigned long long ans = 0;
  for (unsigned long long i = 0; i < n; i++) {
    for (unsigned long long j = 0; j < n; j++) {
      if (c[i] > r[j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
