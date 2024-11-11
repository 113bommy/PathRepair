#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[n], b[m];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
  }
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        cnt++;
        cout << a[i] << " ";
      }
    }
  }
  if (cnt == 0) return 0;
  return 0;
}
