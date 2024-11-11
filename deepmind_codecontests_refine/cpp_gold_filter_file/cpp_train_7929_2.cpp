#include <bits/stdc++.h>
using namespace std;
map<long long, long long> m1;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    m1[a[i]] = 1;
  }
  long long m;
  cin >> m;
  long long b[m];
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
    m1[b[i]] = 1;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (m1[a[i] + b[j]] != 1) {
        cout << a[i] << " " << b[j];
        return 0;
      }
    }
  }
  return 0;
}
