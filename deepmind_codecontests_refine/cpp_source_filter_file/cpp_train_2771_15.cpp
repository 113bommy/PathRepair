#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 0;
  unordered_set<int> st;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    st.insert(x[i]);
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
    st.insert(y[i]);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ans += st.count(x[i] ^ y[i]);
  if (ans & 1)
    cout << "Koyomi";
  else
    cout << "Karen";
  return 0;
}
