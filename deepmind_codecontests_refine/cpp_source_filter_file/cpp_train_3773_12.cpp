#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, j;
  cin >> t;
  for (i = 0; i < t; i++) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (j = 0; j < n; j++) cin >> a[j];
    sort(a, a + n);
    long long int b[n];
    for (j = 0; j < n / 2; j++) {
      b[2 * j] = a[j];
      b[2 * j + 1] = a[n - 1 - j];
    }
    vector<long long int> v1(b, b + n);
    reverse(v1.begin(), v1.end());
    for (j = 0; j < n; j++) cout << v1[j] << " ";
    cout << endl;
  }
}
