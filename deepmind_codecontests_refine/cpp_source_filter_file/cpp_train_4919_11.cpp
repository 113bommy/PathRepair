#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 2e5 + 7;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n - 1; i++) v[i] = 1;
  v[n - 1] = k - n + 1;
  if (n == 1) {
    if (k == 1) {
      cout << "NO";
      return 0;
    } else if (k == 2) {
      cout << "YES\n2\n1";
      return 0;
    }
  }
  if (v[n - 1] == 2) {
    cout << "NO";
  } else {
    cout << "YES\n";
    for (auto i : v) {
      cout << i << " ";
    }
    cout << "\n2";
  }
}
