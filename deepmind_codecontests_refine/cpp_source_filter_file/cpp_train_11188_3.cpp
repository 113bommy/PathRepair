#include <bits/stdc++.h>
using namespace std;
string user[1010][2], ans[1010][2];
int visited[1010];
int main() {
  int n;
  cin >> n;
  int s = 0;
  for (int i = 0; i < n; i++) visited[i] = 0;
  for (int i = 0; i < n; i++) cin >> user[i][0] >> user[i][1];
  for (int i = 0; i < n; i++) {
    if (visited[i] == 0) {
      string temp = user[i][1];
      for (int j = i + 1; j < n; j++) {
        if (user[j][0] == temp) {
          temp = user[j][0];
          visited[j] = 1;
        }
      }
      ans[s][0] = user[i][0];
      ans[s][1] = temp;
      s++;
    } else
      continue;
  }
  cout << s << endl;
  for (int i = 0; i < s; i++) cout << ans[i][0] << " " << ans[i][1] << endl;
  return 0;
}
