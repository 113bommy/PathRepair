#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> one;
    vector<int> two;
    set<int> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'o') {
        if (i + 2 < n) {
          if (s[i + 1] == 'n' && s[i + 2] == 'e') one.push_back(i);
        }
      } else if (s[i] == 't') {
        if (i + 2 < n) {
          if (s[i + 1] == 'w' && s[i + 2] == 'o') two.push_back(i);
        }
      }
    }
    for (auto x : one) {
      if (x > 0) {
        if (s[x - 1] == 'o')
          st.insert(x + 1);
        else
          st.insert(x);
      } else
        st.insert(x);
    }
    for (auto x : two) {
      if (x + 2 < n - 1) {
        if (s[x + 3] == 'o')
          st.insert(x + 1);
        else
          st.insert(x + 2);
      } else
        st.insert(x + 2);
    }
    cout << st.size() << "\n";
    for (auto x : st) cout << x + 1 << " ";
    cout << "\n";
  }
}
