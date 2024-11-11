#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[n], b[m];
  long long k, l;
  cin >> k >> l;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
  }
  if (a[k - 1] < b[m - l]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
