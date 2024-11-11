#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 13;
int n;
int a[2 * MAX];
set<int> st;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int ans = -1;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
    if (st.find(a[i]) != st.end())
      st.erase(a[i]);
    else
      st.insert(a[i]);
    ans = max(ans, (int)st.size());
  }
  cout << ans;
  return 0;
}
