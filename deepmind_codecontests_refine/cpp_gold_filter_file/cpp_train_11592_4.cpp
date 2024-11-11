#include <bits/stdc++.h>
using namespace std;
int n, arr[10], sum, ans[3][3];
bool mark[10], flag;
void ok(int a, int b) {
  if (a == 3 && b == 0) {
    for (int i = 0; i < 3; i++)
      if (ans[i][0] + ans[i][1] + ans[i][2] != sum) return;
    for (int i = 0; i < 3; i++)
      if (ans[0][i] + ans[1][i] + ans[2][i] != sum) return;
    if (ans[0][0] + ans[1][1] + ans[2][2] != sum ||
        ans[0][2] + ans[1][1] + ans[2][0] != sum)
      return;
    flag = true;
  }
  for (int i = 0; i < n * n; i++) {
    if (!mark[i]) {
      if (flag) return;
      mark[i] = true;
      ans[a][b] = arr[i];
      if (b + 1 < n)
        ok(a, b + 1);
      else
        ok(a + 1, 0);
      mark[i] = false;
    }
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sum /= n;
  if (n <= 2) {
    cout << sum << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << arr[0] << " ";
      cout << endl;
    }
    return 0;
  }
  ok(0, 0);
  cout << sum << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
