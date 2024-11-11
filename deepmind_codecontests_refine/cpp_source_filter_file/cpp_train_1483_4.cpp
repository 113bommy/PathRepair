#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> col(m);
  for (long long i = 0; i < m; i++) {
    cin >> col[i];
  }
  vector<long long> suf(m, 0);
  suf[m - 1] = 0;
  for (long long i = m - 2; i >= 0; i--) {
    suf[i] = suf[i + 1] + col[i];
  }
  vector<long long> ans;
  for (long long i = 0, cur = 0, r = 0; i < m; i++) {
    ans.push_back(cur);
    r = cur + col[i];
    if (r > n) {
      cout << "-1" << endl;
      return 0;
    }
    cur++;
    if (suf[i] < n - r) {
      cout << "-1" << endl;
      return 0;
    } else if (suf[i] < n - cur) {
      long long pos = n - suf[i];
      for (long long j = i + 1; j < n; j++) {
        ans.push_back(pos);
        pos += col[j];
      }
      break;
    }
  }
  for (long long i = 0; i < m; i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}
