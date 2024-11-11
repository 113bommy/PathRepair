#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_set<long long> st;
  long long n, x, ans = 0, mx = 0;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> x;
    if (st.find(x) == st.end()) {
      st.insert(x);
      ans++;
    } else {
      st.erase(x);
      ans--;
    }
    mx = max(mx, ans);
  }
  cout << mx << endl;
  return 0;
}
