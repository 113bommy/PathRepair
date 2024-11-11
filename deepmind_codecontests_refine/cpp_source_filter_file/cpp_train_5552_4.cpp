#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int dp[N][27];
int can[27][27];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  set<pair<int, int> > st;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    st.insert(make_pair(b, a));
  }
  int cnt = 1;
  int ans = 0;
  while (st.size() && cnt) {
    pair<int, int> p = *st.rbegin();
    st.erase(st.find(p));
    cnt += p.first;
    ans += p.second;
    cnt--;
  }
  cout << ans << "\n";
  return 0;
}
