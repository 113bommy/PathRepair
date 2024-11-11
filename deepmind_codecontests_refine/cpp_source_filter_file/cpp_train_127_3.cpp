#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int b[m];
    for (long long int i = 0; i < m; i++) cin >> b[i];
    long long int kk = 1000000000, flag = 0;
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) {
        if (a[i] == b[j]) {
          if (a[i] < kk) kk = a[i];
          flag = 1;
        }
      }
    }
    if (flag == 1) {
      cout << "YES" << endl;
      cout << "1 " << kk;
    } else
      cout << "NO" << endl;
  }
}
