#include <bits/stdc++.h>
using namespace std;
inline int getInt() {
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  int num = 0;
  while (ch <= '9' && ch >= '0') {
    num = num * 10 + (ch - '0');
    ch = getchar();
  }
  return num;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, x, ans = 0;
  string st;
  char ch;
  cin >> n >> m;
  cin >> st;
  for (int i = 1; i < st.length(); i++) {
    if (st[i] == '.' && st[i - 1] == '.') ans++;
  }
  for (int i = 1; i <= m; i++) {
    cin >> x >> ch;
    x--;
    if (st[x] == '.' && ch != '.') {
      if (x - 1 >= 0 && st[x - 1] == '.') ans--;
      if (x + 1 < st.length() && st[x + 1] == '.') ans--;
    }
    if (st[x] != '.' && ch == '.') {
      if ((x + 1 < st.length() && st[x + 1] == '.')) {
        ans++;
      }
      if ((x - 1 >= 0 && st[x - 1] == '.')) ans++;
    }
    st[x] = ch;
    cout << ans << endl;
  }
  return 0;
}
