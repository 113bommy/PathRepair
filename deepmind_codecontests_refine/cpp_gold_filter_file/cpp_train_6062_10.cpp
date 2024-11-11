#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> vec(n, 0);
    for (int j = 0; j < n; j++) {
      cin >> vec[j];
      res += vec[j];
    }
    cout << min(res, m) << endl;
  }
  return 0;
}
