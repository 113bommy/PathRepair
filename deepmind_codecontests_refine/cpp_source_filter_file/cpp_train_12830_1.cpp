#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int t, i, j, cnt = 0, x, n;
  cin >> t;
  while (t--) {
    v.clear();
    cnt = 1;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    i = 0;
    j = n - 1;
    cnt = n;
    while (1) {
      if (v[j] <= cnt) {
        break;
      } else {
        j--;
        cnt--;
      }
    }
    cout << cnt + 1 << endl;
  }
  return 0;
}
