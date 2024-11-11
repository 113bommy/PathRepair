#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  cin >> t;
  for (int u = 0; u < t; ++u) {
    int n, k, d;
    cin >> n >> k >> d;
    int minn = 100;
    vector<int> a(n);
    vector<int> colk(k);
    colk.assign(k, 0);
    int coln = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (colk[a[i] - 1] == 0) {
        coln++;
      }
      colk[a[i] - 1]++;
      if (i == d - 1) {
        minn = min(minn, coln);
      } else if (i > d - 1) {
        colk[a[i - d] - 1]--;
        if (colk[a[i - d] - 1] == 0) {
          coln--;
        }
        minn = min(minn, coln);
      }
    }
    cout << minn << endl;
  }
  return 0;
}
