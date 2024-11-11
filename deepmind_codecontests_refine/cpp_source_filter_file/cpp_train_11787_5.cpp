#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
bool vis[N];
set<int> st;
int a[N];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int mx = 0, mn = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[a[i] - 1])
      vis[a[i] - 1] = 1, mx++;
    else if (!vis[a[i]])
      vis[a[i]] = 1, mx++;
    else if (!vis[a[i] + 1])
      vis[a[i] + 1] = 1, mx++;
    st.insert(a[i]);
  }
  memset(vis, 0, sizeof vis);
  for (auto l : st) v.push_back(l);
  if (v.size() == 1)
    mn = 1;
  else {
    for (int i = 1; i < v.size(); i++) {
      if (v[i] - v[i - 1] == 2 && !vis[v[i - 1]]) {
        v[i]--;
        v[i - 1]++;
        vis[v[i]] = 1;
      } else if (v[i] - v[i - 1] == 1) {
        if (vis[i - 1])
          v[i]--;
        else {
          vis[i] = 1;
          v[i - 1]++;
        }
      }
    }
    st.clear();
    for (auto x : v) st.insert(x);
    mn = st.size();
  }
  cout << mn << " " << mx;
}
