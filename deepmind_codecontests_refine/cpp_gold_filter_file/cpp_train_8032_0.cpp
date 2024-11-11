#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w;
  cin >> h >> w;
  int ans[] = {-1, -1};
  char arr[h][w];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) cin >> arr[i][j];
  for (int i = 1; i < h - 1; i = i + 1) {
    if (ans[0] == -1)
      for (int j = 1; j < w - 1; j = j + 1) {
        if (arr[i][j] == '*') {
          if (arr[i - 1][j] == '*' && arr[i][j - 1] == '*' &&
              arr[i + 1][j] == '*' && arr[i][j + 1] == '*') {
            if (arr[i - 1][j - 1] == '.' && arr[i + 1][j + 1] == '.' &&
                arr[i - 1][j + 1] == '.' && arr[i + 1][j - 1] == '.') {
              ans[0] = i;
              ans[1] = j;
            }
          }
        }
      }
    else
      break;
  }
  if (ans[0] == -1) {
    cout << "NO";
    exit(0);
  }
  int te;
  te = ans[0] - 1;
  while (arr[te][ans[1]] == '*') {
    arr[te][ans[1]] = '.';
    te--;
    if (te == -1) break;
  }
  te = ans[0] + 1;
  while (arr[te][ans[1]] == '*') {
    arr[te][ans[1]] = '.';
    te++;
    if (te == h) break;
  }
  te = ans[1] - 1;
  while (arr[ans[0]][te] == '*') {
    arr[ans[0]][te] = '.';
    te--;
    if (te == -1) break;
  }
  te = ans[1];
  while (arr[ans[0]][te] == '*') {
    arr[ans[0]][te] = '.';
    te++;
    if (te == w) break;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (arr[i][j] == '*') {
        cout << "NO";
        exit(0);
      }
    }
  }
  cout << "YES";
}
