#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k, row, col, ans;
    cin >> k;
    long long num = ceil(sqrt(k));
    long long sq = num * num;
    long long d = sq - num;
    if (d < num) {
      row = num;
      col = d + 1;
    } else {
      col = num;
      d -= num;
      d = num - d - 1;
      row = d;
    }
    cout << row << " " << col << endl;
  }
  return 0;
}
