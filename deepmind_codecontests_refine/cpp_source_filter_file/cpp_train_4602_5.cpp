#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, c = 0;
    cin >> n;
    int pOdd = 0, qOdd = 0;
    for (int I = 0; I < n; I++) {
      int temp;
      cin >> temp;
      if (temp % 2) pOdd++;
    }
    cin >> m;
    for (int I = 0; I < m; I++) {
      int temp;
      cin >> temp;
      if (temp % 2) qOdd++;
    }
    cout << (long long)(pOdd * qOdd + (n - pOdd) * (m - qOdd)) << '\n';
  }
}
