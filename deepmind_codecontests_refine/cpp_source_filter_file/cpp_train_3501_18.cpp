#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e6 + 6;
int main() {
  char s[105];
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  while (m--) {
    int l, r;
    char c1[10], c2[10];
    cin >> l >> r >> c1 >> c2;
    for (int i = 1; i <= n; ++i) {
      if (i >= l && i <= r && s[i - 1] == c1[0]) {
        s[i - 1] = c2[0];
      }
    }
    cout << s;
    cout << endl;
  }
  return 0;
}
