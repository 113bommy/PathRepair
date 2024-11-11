#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<string> st;
  while (n--) {
    string s;
    cin >> s;
    st.insert(s);
  }
  cout << st.size() << endl;
}
