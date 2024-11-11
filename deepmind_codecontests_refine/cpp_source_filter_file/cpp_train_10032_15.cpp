#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;
int a[MAXN];
set<int> st;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[j] == (a[j] | a[i])) break;
      a[j] |= a[i];
      st.insert(a[j]);
    }
  }
  cout << st.size() << endl;
  return 0;
}
