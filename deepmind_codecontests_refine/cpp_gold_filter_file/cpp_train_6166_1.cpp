#include <bits/stdc++.h>
using namespace std;
int n, m;
set<string> st;
string a, b, c, x, y;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    y = x;
    reverse(y.begin(), y.end());
    if (x == y) {
      b = x;
    } else {
      if (st.count(y)) {
        a += x;
        c = y + c;
      } else {
        st.insert(x);
      }
    }
  }
  a = a + b + c;
  cout << a.size() << "\n" << a;
  return 0;
}
