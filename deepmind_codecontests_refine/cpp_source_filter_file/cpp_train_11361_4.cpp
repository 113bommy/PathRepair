#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n, k;
  for (int o = 0; o < t; o++) {
    cin >> n >> k;
    for (int i = 1, j = 0; i <= n; i++, j++) {
      if (j == k) j = 0;
      cout << char(j + 65);
    }
    cout << endl;
  }
}
