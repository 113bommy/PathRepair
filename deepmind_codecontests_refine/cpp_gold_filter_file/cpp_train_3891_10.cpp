#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, d;
  cin >> n >> d;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int k = 0, sum = 0;
  for (long long int j = 2; j < n; j++) {
    while (a[j] - a[k] > d) {
      k++;
    }
    sum += ((j - k) * (j - k - 1)) / 2;
  }
  cout << sum << "\n";
  return 0;
}
