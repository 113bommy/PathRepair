#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double EPS = 1e-7;
const int inf = 1e8;
int main() {
  stack<int> st;
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int t = s[i] - '0';
    if (st.size() && (st.top() ^ 1) == 1) {
      st.pop();
    } else
      st.push(t);
  }
  cout << st.size() << endl;
}
