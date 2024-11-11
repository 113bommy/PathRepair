#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s[100005], w, h;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> w >> h;
    if (s[1] > s[w]) {
      cout << s[1] << endl;
      s[1] += h;
    } else {
      cout << s[w] << endl;
      s[1] = s[w] + h;
    }
  }
  return 0;
}
