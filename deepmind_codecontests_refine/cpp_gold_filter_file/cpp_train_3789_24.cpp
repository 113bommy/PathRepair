#include <bits/stdc++.h>
using namespace std;
long long n, m, v, x, q, y, adder;
int t;
long long arr[100009];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t;
    if (t == 1) {
      cin >> v >> x;
      arr[v - 1] = x - adder;
    } else if (t == 2) {
      cin >> y;
      adder += y;
    } else {
      cin >> q;
      cout << arr[q - 1] + adder << endl;
    }
  }
  return 0;
}
