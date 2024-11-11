#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  vector<int> res;
  long long bias = 0;
  for (int k = 0; k < m; k++) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, j;
      cin >> i >> j;
      A[i - 1] = j;
    } else if (t == 2) {
      int a;
      cin >> a;
      bias += a;
    } else if (t == 3) {
      int q;
      cin >> q;
      q--;
      cout << bias + A[q] << "\n";
    }
  }
  return 0;
}
