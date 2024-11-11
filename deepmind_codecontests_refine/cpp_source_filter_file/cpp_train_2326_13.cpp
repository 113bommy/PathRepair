#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int d, n, sum = 0;
  cin >> d;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    sum += d - a[i];
  }
  cout << sum << endl;
  return 0;
}
