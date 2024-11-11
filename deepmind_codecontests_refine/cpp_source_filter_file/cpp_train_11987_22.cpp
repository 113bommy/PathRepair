#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n >= k * (k - 1))
    cout << "NO";
  else {
    cout << "YES\n";
    int cnt = 0;
    for (int i = 1; i <= k; i++)
      for (int j = i + 1; j <= k; j++) {
        cout << i << " " << j << "\n";
        if (++cnt == n) return 0;
        cout << j << " " << i << "\n";
        if (++cnt == n) return 0;
      }
  }
  return 0;
}
