#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] <= 0) sum += a[i];
  }
  if (sum <= 0) {
    cout << abs(sum);
  } else {
    cout << "0";
  }
  return 0;
}
