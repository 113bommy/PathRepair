#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, d, x, y, i, j = 0, dd = 0, mmin = -1, h, xpr = -1e10;
  cin >> n;
  vector<long long> a(n + 1);
  for (i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    a[x]++;
    a[y]++;
  }
  if (a[n] != n - 1) {
    cout << "NO";
    return 0;
  }
  for (i = 0; i < n; ++i) {
    if (a[i] > i) {
      cout << "NO";
      return 0;
    }
  }
  vector<long long> ans;
  stack<long long> st;
  for (i = 1; i < n; ++i) {
    if (a[i] == 0)
      st.push(i);
    else {
      ans.push_back(i);
      for (j = 1; j < a[i]; ++j) {
        if (st.empty()) {
          cout << "NO";
          return 0;
        }
        ans.push_back(st.top());
        st.pop();
      }
    }
  }
  ans.push_back(n);
  cout << "YES";
  for (i = 0; i < ans.size() - 1; ++i) {
    cout << ans[i] << ' ' << ans[i + 1] << endl;
  }
  return 0;
}
