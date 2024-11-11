#include <bits/stdc++.h>
using namespace std;
char S[10005][10];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> S[i];
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cnt = 0;
      for (int a = 0; a < 6; a++) {
        if (S[i][a] != S[j][a]) cnt++;
      }
      ans = min(ans, cnt);
    }
  }
  cout << (ans - 1) / 2 << endl;
  return 0;
}
