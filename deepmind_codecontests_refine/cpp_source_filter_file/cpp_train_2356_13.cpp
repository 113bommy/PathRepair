#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, cnt = 2, m = 0, b = 0;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (long long i = 1; i < n - 1; ++i) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      cnt++;
    }
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) cnt++;
  }
  cout << cnt << endl;
}
