#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxlog = 25;
const int mod = 1e9 + 7;
const int sq = 720;
const int inf = 1e9;
int cnt[maxn], a[maxn];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout.precision(20);
  int n, s;
  cin >> n >> s;
  multiset<int> st;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    st.insert(-a[i]);
  }
  int ans = 0;
  if (a[s] != 0) {
    ans++;
    cnt[0]++;
    st.insert(0);
    cnt[a[s]]--;
    st.erase(st.find(-a[s]));
  }
  ans += cnt[0] - 1;
  int have = cnt[0] - 1;
  for (int i = 1; i <= n; i++) {
    if (i > *st.begin() * -1) break;
    if (cnt[i]) continue;
    if (have) {
      have--;
      continue;
    }
    ans++;
    st.erase(st.begin());
  }
  cout << ans;
  return 0;
}
