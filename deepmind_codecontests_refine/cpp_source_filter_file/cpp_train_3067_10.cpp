#include <bits/stdc++.h>
using namespace std;
set<string> st;
int n;
string s, s1;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> s1;
    st.insert(s + s1);
  }
  cout << st.size();
}
