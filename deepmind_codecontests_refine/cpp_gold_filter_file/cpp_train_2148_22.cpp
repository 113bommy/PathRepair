#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v(200002, 0);
  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v[a] = i + 1;
  }
  int mmin = n + 2;
  int res = -1;
  for (int i = 0; i < 200002; i++) {
    if (v[i] > 0 && v[i] < mmin) {
      mmin = v[i];
      res = i;
    }
  }
  cout << res << endl;
}
