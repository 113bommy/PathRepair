#include <bits/stdc++.h>
using namespace std;
int main() {
  int test, cs = 1;
  cin >> test;
  while (test--) {
    int n, i, j;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ;
    set<int> st;
    for (auto it : v) st.insert(it);
    if (st.size() == 1)
      cout << n << endl;
    else
      cout << 1 << endl;
  }
}
