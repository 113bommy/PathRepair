#include <bits/stdc++.h>
using namespace std;
string num[100];
int h, w;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int main() {
  scanf("%d %d", &h, &w);
  int i = 0;
  while (i < h) {
    cin >> num[i];
    i++;
  }
  int no = 0;
  i = 0;
  while (i < h) {
    int j = 0;
    while (j < w) {
      if (num[i][j] == '.') {
        int cnt = 0;
        int k = 0;
        while (k < 8) {
          int cx = i + dx[k];
          int cy = j + dy[k];
          if (cx >= 0 && cx < h && cy >= 0 && cy < w && num[cx][cy] == '*')
            cnt++;
          k++;
        }
        if (cnt != 8) {
          no = 1;
          break;
        }
      } else if (num[i][j] == '1' || num[i][j] == '2' || num[i][j] == '3' ||
                 num[i][j] == '4' || num[i][j] == '5' || num[i][j] == '6' ||
                 num[i][j] == '7' || num[i][j] == '8') {
        int cnt = 0;
        int k = 0;
        while (k < 8) {
          int cx = i + dx[k];
          int cy = j + dy[k];
          if (cx >= 0 && cx < h && cy >= 0 && cy < w && num[cx][cy] == '*')
            cnt++;
          k++;
        }
        if (cnt != num[i][j] - '0') {
          no = 1;
          break;
        }
      }
      j++;
    }
    i++;
  }
  if (no)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
