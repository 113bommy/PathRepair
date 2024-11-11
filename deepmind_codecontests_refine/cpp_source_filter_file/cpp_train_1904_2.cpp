#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t, n, m, a, sum;
  cin >> t;
  while (t--) {
    sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a;
      sum = sum + a;
    }
    if (sum == m)
      cout << "YES" << endl;
    else
      cout << "NO";
  }
}
