#include <bits/stdc++.h>
using namespace std;
char s[1100], t[1100];
int num[10010];
int main() {
  int n, ans = 0;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      continue;
    } else {
      int flag = -1;
      for (int j = i + 1; j < n; j++) {
        if (s[j] == t[i]) {
          flag = j;
          break;
        }
      }
      if (flag == -1) {
        cout << -1 << endl;
        return 0;
      } else {
        for (int j = flag - 1; j >= i; j--) {
          ans++;
          num[ans] = j;
          swap(s[j], s[j + 1]);
        }
      }
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= ans; i++) {
    if (i != ans)
      cout << num[i] << " ";
    else
      cout << num[i];
  }
  cout << endl;
  return 0;
}
