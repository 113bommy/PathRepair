#include <bits/stdc++.h>
using namespace std;
using namespace __detail;
template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
int getMinimum(string s, int start) {
  int mn = start;
  for (int i = start; i < s.length(); i++) {
    if (((s[i] - 'a') <= (s[mn] - 'a')) && (s[i] - 'a' != s[mn] - 'a')) {
      mn = i;
    }
  }
  return mn;
}
void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  set<int> st;
  for (int i = 0; i < n; i++) {
    int mn = getMinimum(s, i);
    char temp = s[i];
    s[i] = s[mn];
    s[mn] = temp;
    if (i != mn) {
      st.insert(i);
      st.insert(mn);
    }
  }
  int sz = st.size();
  cout << sz << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
