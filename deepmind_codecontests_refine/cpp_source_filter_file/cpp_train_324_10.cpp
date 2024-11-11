#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, k;
  cin >> n;
  vector<long long> a(n);
  long long eve = 0, odd = 0;
  long long sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      eve++;
    } else {
      odd++;
    }
    sum += a[i];
  }
  sort(a.begin(), a.end());
  if (eve == odd - 1 || odd == eve - 1 || odd == eve) {
    cout << 0;
    return 0;
  }
  if (eve == n || odd == n) {
    cout << sum - a[n - 1];
    return 0;
  }
  long long sum1 = 0;
  if (eve > odd) {
    long long xx = eve - odd;
    long long c = 0;
    for (j = 0; j < n; j++) {
      if (c == xx) {
        break;
      }
      if (a[j] % 2 == 0) {
        sum1 += a[j];
        c++;
      }
    }
  } else {
    long long xx = odd - eve;
    long long c = 0;
    for (j = 0; j < n; j++) {
      if (c == xx) {
        break;
      }
      if (a[j] % 2 != 0) {
        sum1 += a[j];
      }
      c++;
    }
  }
  cout << sum1;
}
