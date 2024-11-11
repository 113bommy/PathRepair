#include <bits/stdc++.h>
using namespace std;
int n, d, a[2000];
long long sum;
int main() {
  cin >> d >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += (d - a[i]);
  }
  sum -= a[n - 1];
  cout << sum;
  return 0;
}
