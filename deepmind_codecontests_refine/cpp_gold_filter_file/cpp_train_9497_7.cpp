#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> shad(1001, vector<int>(1001, 0));
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  bool flag = true;
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    shad[a][b]++;
    shad[a][0]++;
    shad[b][a]++;
    shad[b][0]++;
  }
  int c, i_1, i_2, ans;
  ans = 0;
  while (flag) {
    c = 0;
    i_1 = 0;
    i_2 = 0;
    for (int i = 1; i < n + 1; ++i)
      if (shad[i][0] == 1) {
        if (i_1)
          i_2 = i;
        else
          i_1 = i;
        if (i_2) break;
      }
    if (i_2 == 0 || i_1 == 0) {
      cout << "! " << ans;
      return 0;
    }
    cout << "? " << i_1 << " " << i_2 << "\n";
    cout.flush();
    cin >> ans;
    if (ans == i_1 || ans == i_2) {
      cout << "! " << ans;
      return 0;
    }
    shad[i_1][0] = 0;
    shad[i_2][0] = 0;
    for (int i = 1; i < n + 1; ++i) {
      if (shad[i][i_1]) {
        shad[i][0]--;
        shad[i][i_1]--;
      }
      if (shad[i][i_2]) {
        shad[i][0]--;
        shad[i][i_2]--;
      }
    }
  }
  return 0;
}
