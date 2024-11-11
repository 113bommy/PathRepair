#include <bits/stdc++.h>
using namespace std;
string s[200];
int n, cnt, m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'B') {
        while (s[i][j] == 'B') {
          cnt++;
          j++;
        }
        cnt = (cnt / 2) + 1;
        cout << i + cnt << " " << j - cnt + 1;
        return 0;
      }
    }
  }
}
