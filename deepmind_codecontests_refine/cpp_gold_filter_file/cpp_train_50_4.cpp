#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> st;
  int n, m, x, t;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> t;
      st.insert(t);
    }
  }
  if (st.size() == m)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
