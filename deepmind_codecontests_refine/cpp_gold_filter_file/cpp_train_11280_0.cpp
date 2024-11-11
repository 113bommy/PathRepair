#include <bits/stdc++.h>
using namespace std;
int n, m;
int k;
vector<int> ans;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) ans.push_back(1);
  int r = n;
  int qr = k;
  while (r < n + m + 1) {
    if (qr == k) {
      ans.push_back(r);
      qr = 1;
      r++;
      if (r < n + m + 1) {
        bool was = false;
        while (qr < k) {
          was = true;
          ans.push_back(r);
          qr++;
        }
        if (!was) r--;
        r = r + n - 1;
      }
    } else {
      while (qr < k) {
        ans.push_back(r);
        qr++;
      }
      r = r + n - 1;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  return 0;
}
