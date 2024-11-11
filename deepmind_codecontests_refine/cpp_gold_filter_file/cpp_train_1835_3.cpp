#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const long long int mod = 1e9 + 7;
const long long int mx = 1e16;
bool comp(const int a, const int b) { return a > b; }
const double PI = 2 * acos(0.0);
long long int pay[2005][505];
long long int cost[505];
int main() {
  set<char> st;
  int n, f, ans = 0;
  cin >> n;
  string s;
  cin >> s;
  for (long long int i = 0; i < n; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      st.insert(s[i]);
      if (st.size() > ans) ans = st.size();
    } else {
      st.clear();
    }
  }
  cout << ans << endl;
}
