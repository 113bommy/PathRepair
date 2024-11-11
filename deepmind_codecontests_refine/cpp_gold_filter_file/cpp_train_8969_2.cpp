#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int q;
  cin >> q;
  int n, k;
  while (q--) {
    cin >> n >> k;
    int v[n];
    int odd = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      odd += (v[i] % 2 == 1);
    }
    if (k > odd || (odd % 2 != k % 2))
      cout << "NO" << '\n';
    else {
      cout << "YES" << endl;
      for (int i = 0; k > 1; i++) {
        if (v[i] % 2 == 1) {
          cout << i + 1 << " ";
          k--;
        }
      }
      cout << n << '\n';
    }
  }
}
