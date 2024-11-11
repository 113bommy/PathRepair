#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
X:
  while (t--) {
    int n;
    cin >> n;
    std::vector<int> v(n);
    std::vector<int> ara(1025, 0);
    int mx = -1;
    set<int> ma;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
      ma.insert(x);
      mx = max(x, mx);
      ara[x]++;
    }
    for (int i = 1; i <= mx; i++) {
      int c = 1;
      std::vector<int> ara2;
      ara2 = ara;
      set<int> st;
      for (auto x : v) {
        int temp = x ^ i;
        st.insert(temp);
      }
      if (ma == st) {
        cout << i << endl;
        goto X;
      }
    }
    cout << -1 << endl;
  }
  return 0;
}
