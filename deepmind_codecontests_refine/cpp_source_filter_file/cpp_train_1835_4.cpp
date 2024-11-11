#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x, k = 0;
  set<char> st[205];
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] < 'a') {
      k++;
      continue;
    }
    st[k].insert(s[i]);
  }
  int mx = -1;
  for (int i = 0; i < k; i++) {
    x = st[i].size();
    mx = max(x, mx);
  }
  cout << mx << endl;
  return 0;
}
