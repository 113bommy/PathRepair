#include <bits/stdc++.h>
using namespace std;
const long long int N = 5000 + 5;
const long long int LOG = 20 + 5;
const long long int MOD = 1e9 + 7;
const long long int INF = 2e9 + 10;
const long long int INFtar = 1e18 + 10;
int n;
set<long long int> st;
long long int ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long int h;
    cin >> h;
    st.insert(-h);
    while (st.size() && h < -(*st.begin())) {
      ans += -(*st.begin()) - h;
      st.erase(st.begin());
      st.insert(-h);
    }
  }
  cout << ans << '\n';
  return 0;
}
