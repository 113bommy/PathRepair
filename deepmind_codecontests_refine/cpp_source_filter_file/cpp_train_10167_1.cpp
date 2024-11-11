#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
constexpr int KINF = 0x3f3f3f3f;
constexpr int INF = 0x7f7f7f7f;
constexpr double eps = 1e-7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  map<long long, set<int>> mp;
  int ans = n;
  set<long long> st;
  vector<long long> a(n);
  for (int i = (int)0; i < (int)n; ++i) {
    cin >> a[i];
    mp[a[i]].insert(i);
    st.insert(a[i]);
  }
  while (!st.empty()) {
    int mi = *st.begin();
    if (mp[mi].size() < 2)
      st.erase(st.begin());
    else {
      while (mp[mi].size() >= 2) {
        int i = *mp[mi].begin();
        mp[mi].erase(i);
        int j = *mp[mi].begin();
        mp[mi].erase(j);
        a[i] = -1;
        a[j] *= 2;
        mp[a[j]].insert(j);
        st.insert(a[j]);
        ans -= 1;
      }
      st.erase(st.begin());
    }
  }
  cout << ans << "\n";
  for (int i = (int)0; i < (int)n; ++i)
    if (a[i] != -1) cout << a[i] << " ";
  cout << "\n";
  return 0;
}
