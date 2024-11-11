#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      st.insert(x);
    }
    if (k < (int)st.size())
      cout << -1 << endl;
    else {
      int y = 1;
      while (k < (int)st.size()) {
        st.insert(y);
        y++;
      }
      cout << n * k << endl;
      for (int i = 0; i < n; i++) {
        for (auto j : st) cout << j << " ";
      }
      cout << endl;
    }
  }
}
