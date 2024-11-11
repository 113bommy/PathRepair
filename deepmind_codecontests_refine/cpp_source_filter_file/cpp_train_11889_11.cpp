#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> vis(n + 1, false);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    stack<int> st;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      int x = i;
      st.push(arr[x]);
      vis[x] = true;
      while (st.top() != i) {
        x = arr[x];
        st.push(arr[x]);
        vis[x] = true;
      }
      int siz = st.size();
      while (!st.empty()) {
        ans[st.top()] = siz;
        st.pop();
      }
    }
    for (int i = 1; i < n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
