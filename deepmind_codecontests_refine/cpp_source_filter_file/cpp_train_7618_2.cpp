#include <bits/stdc++.h>
using namespace std;
const int Dim = 501;
int a[Dim][Dim], n, m, s;
stack<pair<int, int>> st;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (!a[i][j]) st.push(make_pair(i, j));
      s += a[i][j];
    }
  int i, j;
  while (!st.empty()) {
    tie(i, j) = st.top();
    a[i][j] = min(a[i + 1][j], a[i][j + 1]) - 1;
    s += a[i][j];
    st.pop();
  }
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (a[i][j] <= a[i - 1][j]) s = -1;
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= n; ++j)
      if (a[i][j] <= a[i][j - 1]) s = -1;
  cout << s;
}
