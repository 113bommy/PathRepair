#include <bits/stdc++.h>
using namespace std;
char a[200 * 1000 + 7];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k, p, len, i, maxship = 0, z;
  vector<long long> ans;
  cin >> n >> k >> len >> p;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = '1';
  n++;
  z = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] == '0') {
      z++;
    } else {
      maxship += z / len;
      z = 0;
    }
  }
  z = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] == '0') {
      z++;
      if (z % len == 0) {
        ans.push_back(i);
        maxship--;
        if (maxship < k) break;
      }
    } else {
      z = 0;
    }
  }
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
