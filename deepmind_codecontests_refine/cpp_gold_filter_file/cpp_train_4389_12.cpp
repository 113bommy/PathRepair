#include <bits/stdc++.h>
using namespace std;
char s[200010], t[200010];
int S[200010], T[200010], ans[200010];
int main() {
  int k, i, up = 0;
  cin >> k;
  for (i = 1; i <= k; i++) {
    cin >> s[i];
    S[i] = s[i] - 'a';
  }
  for (i = 1; i <= k; i++) {
    cin >> t[i];
    T[i] = t[i] - 'a';
  }
  for (i = k; i >= 1; i--) {
    ans[i] = (S[i] + T[i] + up) % 26;
    up = (S[i] + T[i] + up) / 26;
  }
  ans[0] = up;
  int down = 0;
  for (i = 0; i <= k; i++) {
    int x = ans[i];
    ans[i] = (ans[i] + down) / 2;
    down = (x + down) % 2 * 26;
    if (i != 0) cout << char(ans[i] + 'a');
  }
  cout << endl;
}
