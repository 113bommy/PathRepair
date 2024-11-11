#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
char a[MAXN];
int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int res = 0;
  int flag = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      ++flag;
      while (flag > 0 && i < n) {
        if (s[++i] == '(')
          ++flag;
        else
          --flag;
      }
    } else {
      --flag;
      ++res;
      while (flag < 0 && i < n) {
        if (s[++i] == '(')
          ++flag;
        else
          --flag;
        ++res;
      }
    }
  }
  if (!flag)
    cout << res << endl;
  else
    cout << -1 << endl;
  return 0;
}
