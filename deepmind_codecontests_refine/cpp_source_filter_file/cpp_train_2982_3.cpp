#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, next = 1;
  scanf("%d %d", &n, &k);
  vector<int> v(k);
  stack<int> st;
  for (int i = 0; i < k; i++) {
    scanf("%d", &v[i]);
    if (!st.empty() && st.top() < v[i]) {
      printf("-1\n");
      return 0;
    }
    st.push(v[i]);
    while (!st.empty() && st.top() == next) {
      next = st.top() + 1;
      st.pop();
    }
  }
  while (!st.empty()) {
    int t = st.top();
    for (int i = t - 1; i >= next; i--) v.push_back(i);
    next = t;
    st.pop();
  }
  int i = n;
  while ((int)v.size() < n) v.push_back(i--);
  for (int i = 0; i < n; i++) printf("%d ", v[i]);
}
