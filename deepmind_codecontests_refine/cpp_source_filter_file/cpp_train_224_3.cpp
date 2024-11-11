#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<pair<int, int>> st, re;
    int a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      st.emplace_back(a, b);
      re.emplace_back(b, a);
    }
    sort(st.begin(), st.end());
    sort(re.begin(), re.end());
    cout << st[n - 1].first - re[0].first << "\n";
  }
  return 0;
}
