#include <bits/stdc++.h>
using namespace std;
int n, v[1000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; ++i) {
      cout << v[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
