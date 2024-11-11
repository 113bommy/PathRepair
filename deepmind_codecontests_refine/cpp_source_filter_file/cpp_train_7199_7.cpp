#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 233;
int a[maxn], b[maxn], vis[maxn];
int n;
int go() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i]) ans = max(ans, i - b[i] + 1);
  }
  return ans + n;
}
int go2() {
  set<int> st;
  for (int i = 1; i <= n; i++)
    if (a[i]) st.insert(a[i]);
  int ans = 0;
  int p = 1;
  while (st.size() && ans < n) {
    b[n + p] = *st.begin();
    st.erase(st.begin());
    if (b[p]) st.insert(b[p]);
    ans++, p++;
  }
  int t = 1;
  while (b[t] != 1) t++;
  for (int i = t, j = 1; j <= n; i++, j++)
    if (b[i] + 1 != b[i + 1]) return INT_MAX;
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  cout << min(go(), go2());
}
