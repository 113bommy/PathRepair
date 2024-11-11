#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    cin >> n;
    long long int a[n];
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    sort(a, a + n);
    for (int i = 1; i < n / 2 + 1; i++) {
      cout << a[i] << " " << a[0] << "\n";
    }
  }
  return 0;
}
