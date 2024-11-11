#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int a[n + 2000];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = n - 1; i >= 0; i--) {
    for (long long int j = 0; j < i; j++) {
      if (a[j] > a[j + 1]) {
        long long int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
  long long int ot = 0;
  long long int floor = 1;
  long long int sum = 0;
  long long int ot2;
  long long int maxF = a[n - 1] - 1;
  while (ot < n) {
    long long int minF = abs(a[ot] - floor);
    ot2 = 0;
    for (long long int i = ot; i < n; i += k) {
      for (long long int j = i; j < i + k; j++) {
        a[j] -= a[ot];
        if (a[j] == 0) ot2++;
      }
      sum += minF;
      if (i + k < n) sum += minF;
    }
    ot += ot2;
    floor += minF;
  }
  sum += maxF;
  cout << sum;
}
