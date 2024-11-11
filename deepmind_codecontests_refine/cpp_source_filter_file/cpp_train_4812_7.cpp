#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n, m, k;
    cin >> n >> m >> k;
    k = min(k, m - 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int maksi = 0;
    for (int i = 0; i <= k; i++) {
      int fin = n - 1 - k + i;
      int rem = m - 1 - k;
      int mini = 1 << 29;
      for (int j = i; j <= i + rem; j++) {
        mini = min(max(a[j], a[fin - rem + j - i]), mini);
      }
      maksi = max(maksi, mini);
    }
    cout << maksi << endl;
  }
}
