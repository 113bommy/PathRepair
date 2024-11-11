#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  vector<int> vt;
  for (int i = 1; i <= 1000; i++) {
    if ((i % 3) && (i % 10 != 3)) vt.push_back(i);
  }
  while (t--) {
    int k = 0;
    cin >> k;
    cout << vt[k - 1] << "\n";
  }
  return 0;
}
