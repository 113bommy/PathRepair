#include <bits/stdc++.h>
using namespace std;
int ans[200002] = {0};
void fill() {
  for (int i = 0; i < 200002; i++) ans[i] = 1e7;
}
int main() {
  fill();
  int n;
  cin >> n;
  int arr[200002];
  queue<int> q;
  stack<int> st;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) q.push(i), st.push(i);
  }
  for (int i = 0; i < n; i++) {
    if (q.size() != 0) {
      if (q.front() >= i)
        ans[i] = q.front() - i;
      else {
        q.pop();
        if (q.size() != 0) ans[i] = q.front() - i;
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (st.size() != 0) {
      if (st.top() <= i)
        ans[i] = min(ans[i], i - st.top());
      else {
        st.pop();
        if (st.size() != 0) ans[i] = min(ans[i], i - st.top());
      }
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
