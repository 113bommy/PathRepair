#include <bits/stdc++.h>
using namespace std;
const int base = 1000 * 1000 * 1000;
const double PI = acos(-1.0);
const long long N = 1e5 + 1;
const long long MOD = 1000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int x = n % 4;
  n /= 4;
  vector<char> st;
  for (int i = 0; i < 4; i++) {
    st.push_back('a'), st.push_back('b'), st.push_back('c'), st.push_back('d');
  }
  if (x != 0) {
    for (int i = 'a'; i < 'a' + x; i++) st.push_back(i);
  }
  for (char xt : st) cout << xt;
}
