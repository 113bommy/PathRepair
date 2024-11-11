#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000010];
bool used[1000010];
stack<int> st;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  scanf("%d", &m);
  memset(used, false, sizeof(used));
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    x--;
    used[x] = true;
    a[x] *= -1;
  }
  while (!st.empty()) st.pop();
  for (int i = n - 1; i >= 0; --i) {
    if (!st.empty()) {
      if (abs(a[st.top()]) == a[i]) {
        a[st.top()] = -a[i];
        st.pop();
      } else
        st.push(i);
    } else
      st.push(i);
  }
  if (!st.empty())
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  }
  return 0;
}
