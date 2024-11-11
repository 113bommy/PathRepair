#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int main() {
  long long n;
  cin >> n;
  long long mn = 1000000001;
  long long ind = 0;
  for (int k = 1; k <= n; k++) {
    cin >> a[k];
    if (a[k] < mn) {
      mn = a[k];
      ind = k;
    }
  }
  for (int k = 1; k <= n; k++) {
    a[k] -= mn;
  }
  long long t = 0;
  if (mn > n)
    ind = 1 + mn % n;
  else
    ind = 1 + mn;
  for (int k = ind; k <= n; k++) {
    if (a[k] - t <= 0) {
      cout << k;
      return 0;
    }
    t++;
    if (k == n) k = 1;
  }
  return 0;
}
