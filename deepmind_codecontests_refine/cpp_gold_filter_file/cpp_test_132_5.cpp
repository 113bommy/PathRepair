#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int b[8];
    for (int i = 1; i <= 7; ++i) cin >> b[i];
    int first = b[7] - b[6];
    int last = b[7] - b[5];
    cout << first << ' ' << b[7] - (first + last) << ' ' << last << endl;
  }
  return 0;
}
