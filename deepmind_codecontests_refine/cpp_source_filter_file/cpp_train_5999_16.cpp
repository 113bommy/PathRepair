#include <bits/stdc++.h>
using namespace std;
inline bool ascending(int i, int j) { return (i < j); }
inline bool descending(int i, int j) { return (i > j); }
const int MN = 100000 + 51;
int main() {
  int n, res = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    res = max(res, temp);
  }
  cout << max(1, res - 25) << endl;
  return 0;
}
