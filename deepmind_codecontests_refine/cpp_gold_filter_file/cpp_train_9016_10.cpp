#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> k >> m;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int rem[100005];
  memset(rem, 0, sizeof(rem));
  for (int i = 0; i < n; i++) {
    rem[a[i] % m]++;
  }
  for (int i = 0; i < 100005; i++) {
    if (rem[i] >= k) {
      cout << "Yes" << endl;
      for (int j = 0, kk = 0; j < n && kk < k; j++) {
        if (a[j] % m == i) {
          cout << a[j] << " ";
          kk++;
        }
      }
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
