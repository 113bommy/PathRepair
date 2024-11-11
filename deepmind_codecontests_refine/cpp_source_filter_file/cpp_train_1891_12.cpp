#include <bits/stdc++.h>
using namespace std;
int que[200], ans[100];
int book[100];
int pre[10] = {0, 4, 8, 15, 16, 23, 42};
int main() {
  cout << "? " << 1 << " " << 2 << endl;
  fflush(stdout);
  cin >> que[1];
  cout << "? " << 3 << " " << 4 << endl;
  fflush(stdout);
  cin >> que[2];
  if (que[1] % 23 == 0) {
    cout << "? " << 5 << " " << 5 << endl;
    fflush(stdout);
    cin >> que[3];
    int temp = que[1] / 23;
    cout << "? " << 1 << " " << 3 << endl;
    fflush(stdout);
    cin >> que[4];
    if (que[4] % 23 == 0)
      ans[1] = 23, ans[2] = temp;
    else
      ans[1] = temp, ans[1] = 23;
    ans[3] = que[4] / ans[1];
    ans[4] = que[2] / ans[3];
    ans[5] = sqrt(que[3]);
    for (int j = 1; j <= 6; j++) {
      if (pre[j] != ans[1] && pre[j] != ans[2] && pre[j] != ans[3] &&
          pre[j] != ans[4] && pre[j] != ans[5])
        ans[6] = pre[j];
    }
    cout << "! ";
    for (int i = 1; i <= 6; i++) cout << ans[i] << " ";
    cout << endl;
    fflush(stdout);
  } else if (que[2] % 23 == 0) {
    cout << "? " << 5 << " " << 5 << endl;
    fflush(stdout);
    cin >> que[3];
    int temp = que[2] / 23;
    cout << "? " << 1 << " " << 3 << endl;
    fflush(stdout);
    cin >> que[4];
    if (que[4] % 23 == 0)
      ans[3] = 23, ans[4] = temp;
    else
      ans[3] = temp, ans[4] = 23;
    ans[1] = que[4] / ans[3];
    ans[2] = que[1] / ans[1];
    ans[5] = sqrt(que[3]);
    for (int j = 1; j <= 6; j++) {
      if (pre[j] != ans[1] && pre[j] != ans[2] && pre[j] != ans[3] &&
          pre[j] != ans[4] && pre[j] != ans[5])
        ans[6] = pre[j];
    }
    cout << "! ";
    for (int i = 1; i <= 6; i++) cout << ans[i] << " ";
    ;
    cout << endl;
    fflush(stdout);
  } else {
    for (int i = 1; i <= 6; i++) {
      for (int j = i + 1; j <= 6; j++) {
        if (pre[i] * pre[j] == que[1]) ans[1] = pre[i], ans[2] = pre[j];
      }
    }
    for (int i = 1; i <= 6; i++) {
      for (int j = i + 1; j <= 6; j++) {
        if (pre[i] * pre[j] == que[2]) ans[3] = pre[i], ans[4] = pre[j];
      }
    }
    for (int i = 1; i <= 6; i++) {
      if (pre[i] != ans[1] && pre[i] != ans[2] && pre[i] != ans[3] &&
          pre[i] != ans[4]) {
        if (ans[5] == 0)
          ans[5] = pre[i];
        else
          ans[6] = pre[i];
      }
    }
    cout << "? " << 1 << " " << 5 << endl;
    fflush(stdout);
    cin >> que[3];
    if (que[3] % 23 == 0) {
      if (ans[5] != 23) swap(ans[5], ans[6]);
      ans[1] = que[3] / ans[5];
      ans[2] = que[1] / ans[1];
      cout << "? " << 3 << " " << 5 << endl;
      fflush(stdout);
      cin >> que[4];
      ans[3] = que[4] / ans[5];
      ans[4] = que[2] / ans[3];
    } else {
      if (ans[5] == 23) swap(ans[5], ans[6]);
      ans[1] = que[3] / ans[5];
      ans[2] = que[1] / ans[1];
      cout << "? " << 3 << " " << 5 << endl;
      fflush(stdout);
      cin >> que[4];
      ans[3] = que[4] / ans[5];
      ans[4] = que[2] / ans[3];
    }
    cout << "! ";
    for (int i = 1; i <= 6; i++) cout << ans[i] << " ";
    ;
    cout << endl;
    fflush(stdout);
  }
  return 0;
}
