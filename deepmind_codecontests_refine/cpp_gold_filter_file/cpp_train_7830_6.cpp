#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  int cnt = 0;
  int v = 0;
  bool flag = true;
  for (int x = 0; x < S.size(); x++) {
    if (S[x] == '(')
      cnt++;
    else
      cnt--;
    if (cnt == 0 and !flag) {
      ans += x - v + 1;
      v = x + 1, flag = true;
    } else if (cnt == 0)
      v = x + 1;
    if (cnt < 0) flag = false;
  }
  if (cnt)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
