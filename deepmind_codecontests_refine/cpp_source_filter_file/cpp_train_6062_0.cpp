#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s, x, y = 0, m;
  cin >> n;
  for (x = 0; x < n; x++) {
    cin >> s >> m;
    long long ma[m];
    for (y = 0; y < s; y++) {
      cin >> ma[y];
    }
    y = 0;
    while (ma[0] != m && y < s) {
      if (ma[y + 1] != 0) {
        ma[0]++;
        ma[y + 1]--;
      } else
        y++;
    }
    cout << ma[0] << endl;
  }
  return 0;
}
