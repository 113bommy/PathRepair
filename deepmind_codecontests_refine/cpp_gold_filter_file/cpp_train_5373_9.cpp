#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  string s;
  set<char> st;
  cin >> s >> n;
  for (int i = 0; i < s.size(); i++) st.insert(s[i]);
  if (n > s.size())
    cout << "impossible";
  else {
    n -= st.size();
    cout << max(0ll, n);
  }
  return 0;
}
