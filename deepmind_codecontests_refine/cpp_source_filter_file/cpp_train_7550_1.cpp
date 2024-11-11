#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
string s;
set<char> st;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) st.insert(s[i]);
  if (st.size() == 1 and n >= 3) {
    cout << -1;
    return 0;
  }
  cout << n - st.size();
}
