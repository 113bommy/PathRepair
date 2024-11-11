#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, mul = 1, z = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      mul += a[i];
      if (a[i] == 0) z++;
    }
    if (sum != 0 && mul != 0)
      cout << 0 << '\n';
    else {
      if (sum == -z)
        cout << z + 1 << '\n';
      else
        cout << z << '\n';
    }
  }
}
