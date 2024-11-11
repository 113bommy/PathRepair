#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string enemy, gregor;
    cin >> enemy;
    cin >> gregor;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (gregor[i] == '0')
        continue;
      else if (enemy[i] == '0')
        ans++;
      else if ((i - 1) >= 0 and enemy[i - 1] == '1') {
        enemy[i - 1] = 'x';
        ans++;
      } else if ((i + 1) < n and enemy[i + 1] == '1') {
        enemy[i + 1] = 'x';
        ans++;
      }
    }
    cout << ans << endl;
  }
}
