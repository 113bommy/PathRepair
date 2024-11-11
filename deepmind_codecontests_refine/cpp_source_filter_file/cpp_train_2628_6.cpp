#include <bits/stdc++.h>
using namespace std;
int n, m, t, sum[1005];
string s;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> m;
    if (n == 0 or m == 0) {
      sum[i] = 1;
    } else if (n + m == 4) {
      sum[i] = 1;
    }
  }
  for (int i = 0; i < t; i++) {
    if (sum[i] == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
